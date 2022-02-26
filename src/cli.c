/*============================================================================
 * Name        : cli.c
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 26/02/2022
 * Description : Source file containing commandline-interface functions definitions
 *============================================================================*/

#include "cli.h"

// Returns if the command starts with "bill"
bool cliStartsWithBill(const char *command) {
    if(command[0] != 'b') return false;
    if(command[1] != 'i') return false;
    if(command[2] != 'l') return false;
    if(command[3] != 'l') return false;
    if(command[4] != ' ') return false;

    return true;
}

/* Loads dest with the main flag of the passed command ("--example")
(dest_s is the size of dest excluding the additional NULL terminating character '\0')*/
int cliGetMainFlag(char *dest, const char *command, size_t dest_s) {
    memset(dest, 0, dest_s + 1);
    
    for(int i = 0; i < strlen(command); i++) {
        if(command[i] == ' ' && command[i+1] == '-' && command[i+2] == '-') {
            for(int j = i + 1; command[j] != ' ' && command[j] != '\0'; j++) {
                strncat(dest, charToString(command[j]), dest_s);
            }    

            return 0;
        }
    }

    return -1;
}

/* Loads dest with the subflags of the passed command ex:("-a", "-b", ...) and
returns the number of subflags found in the command */
int cliGetSubFlags(char dest[][3], const char *command) {
    const size_t command_s = strlen(command);
    char *temp_command = malloc(sizeof(char) * (command_s + 2));
    char temp_subflag[3];
    int n_of_flags = 0;

    memset(temp_subflag, 0, 3);
    memset(temp_command, 0, command_s + 2);

    // Copy of the command in a temp_command (not to modify the original command)
    strcpy(temp_command, command);

    // Adding a space at the end of temp_command, otherwise flags at the end wouldn't work
    strcat(temp_command, " ");

    for(int i = 0; i < strlen(temp_command) - 3; i++) {
        if(temp_command[i] == ' ' && temp_command[i+1] == '-' && temp_command[i+3] == ' ') {
            // Copying the subflag in temp_subflag
            strcat(temp_subflag, charToString(command[i+1]));
            strcat(temp_subflag, charToString(command[i+2]));

            // Copying the temp_subflag in the flags list
            strcpy(dest[n_of_flags], temp_subflag);
            
            // Ereasing the temp_subflag
            memset(temp_subflag, 0, 3);

            n_of_flags++;
        }
    }

    free(temp_command);

    return n_of_flags;
}

/* Loads dest with the argument relative to the passed flag
(dest_s is the size of dest excluding the additional NULL terminating character '\0')*/
int cliGetArgument(char *dest, const char *command, const char *flag, size_t dest_s) {
    int match_count = 0;
    int pos = -1;

    memset(dest, 0, dest_s + 1);

    // Finds the position (of the first char) of the first occurrence of 'flag'
    for(int i = 0; i < strlen(command) - strlen(flag); i++) {
        for(int j = i, k = 0; j < strlen(flag) + i; j++, k++) {
            if(command[j] == flag[k]) {
                match_count++;
            }

            if(match_count == strlen(flag)) pos = j - strlen(flag) + 1;
        }

        match_count = 0;
    }

    if(pos == -1) return pos; // No arguments found

    // Loading dest with the argument
    for(int i = pos + strlen(flag) + 1; command[i] != ' ' && command[i] != '\0'; i++) {
        strncat(dest, charToString(command[i]), dest_s);
    }

    return 0;
}