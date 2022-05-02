/*============================================================================
 * Name        : cli.c
 * Version     : v1.2.0
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : 2022 Francesco Cristiano Aliprandi
 * License     : MIT
 * Description : Source file containing commandline-interface functions definitions
 *============================================================================*/

#include "cli.h"

/* Loads dest with the entire commandline command ("billman --example -e 999") */
int cliExtractCommand(char *dest, int argc, char *argv[]) {
    memset(dest, 0, COMM_MAXLEN + 1);

    for(int i = 0; i < argc; i++) {
        strncat(dest, argv[i], COMM_MAXLEN);

        if(i != argc - 1) {
            strncat(dest, " ", COMM_MAXLEN);
        }
    }

    return 0;
}

/* Loads dest with the main flag of the passed command ("--example")
(dest_s is the size of dest excluding the additional NULL terminating character '\0')*/
int cliGetMainFlag(char *dest, const char *command, size_t dest_s) {
    memset(dest, 0, dest_s + 1);

    for(int i = 0; i < strlen(command) - 2; i++) {
        if(command[i] == ' ' && command[i+1] == '-' && command[i+2] == '-') {   
            for(int j = i + 1; command[j] != ' ' && command[j] != '\0'; j++) {
                strncat(dest, utilsCharToString(command[j]), dest_s);
            }    

            return 0;
        }
    }

    return -1;
}

/* Loads dest with the subflags of the passed command ex:("-a", "-b", ...) and
returns the number of subflags found in the command */
size_t cliGetSubFlags(char ***dest, const char *command) {
    const size_t command_s = strnlen(command, COMM_MAXLEN);
    char *temp_command = malloc(sizeof(char) * (command_s + 2));
    char temp_subflag[SUBFLAG_LEN + 1];
    size_t n_of_flags = 0;

    // Failed allocation
    if(temp_command == NULL) return EXIT_FAILURE;

    memset(temp_command, 0, command_s + 2);

    /* ---- Copy of the command (not to modify the original command) ---- */
    strncpy(temp_command, command, command_s);
    strncat(temp_command, " ", command_s + 1); // Adding a space at the end (otherwise subflags at the end would't be found)

    *dest = malloc(sizeof(char *) * 10);

    // Failed allocation
    if(*dest == NULL) return EXIT_FAILURE;

    for(int i = 0; i < strlen(temp_command) - 3; i++) {
        if(temp_command[i] == ' ' && temp_command[i+1] == '-' && temp_command[i+3] == ' ') {
            // Ereasing the temp_subflag
            memset(temp_subflag, 0, SUBFLAG_LEN + 1);

            // Copying the subflag in temp_subflag
            strncat(temp_subflag, utilsCharToString(temp_command[i+1]), SUBFLAG_LEN);
            strncat(temp_subflag, utilsCharToString(temp_command[i+2]), SUBFLAG_LEN);

            /* ---- Allocating memory for the new subflag and copying ---- */
            (*dest)[n_of_flags] = malloc(sizeof(char) * (SUBFLAG_LEN + 1));

            // Failed allocation
            if((*dest)[n_of_flags] == NULL) return EXIT_FAILURE;
            
            memset((*dest)[n_of_flags], 0, SUBFLAG_LEN + 1);
            strncpy((*dest)[n_of_flags], temp_subflag, SUBFLAG_LEN);

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
        strncat(dest, utilsCharToString(command[i]), dest_s);
    }

    return 0;
}