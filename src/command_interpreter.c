/*============================================================================
 * Name        : command_interpreter.c
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 18/02/2022
 * Description : Source file containing commandline-interface functions definitions
 *============================================================================*/

#include "command_interpreter.h"

// Returns if the command starts with "bill"
bool startsWithBill(const char* command) {
    if(command[0] != 'b') return false;
    if(command[1] != 'i') return false;
    if(command[2] != 'l') return false;
    if(command[3] != 'l') return false;
    if(command[4] != ' ') return false;

    return true;
}

// Returns the main flag of the passed command ("--example")
void findMainFlag(char* dest, const char* command, size_t dest_s) {
    char cts[2];

    memset(dest, 0, dest_s);
    
    for(int i = 0; i < strlen(command); i++) {
        if(command[i] == ' ' && command[i+1] == '-' && command[i+2] == '-') {
            for(int j = i + 1; command[j] != ' ' && command[j] != '\0'; j++) {
                charToString(cts, command[j]);
                strcat(dest, cts);
            }    

            break;
        }
    }

    dest[strlen(dest)] = '\0';
}

// Returns a vector containing all the flags of the passed command ("-a", "-b", ...)
char** findFlags(char* command) {
    char** flags;
    char* temp = "";

    // Adding a space to the end, otherwise flags at the end wouldn't work
    strcat(command, " ");

    for(int i = 0; i < strlen(command) - 3; i++) {
        if(command[i] == ' ' && command[i+1] == '-' && command[i+3] == ' ') {
            strcat(temp, command[i+1]);
            strcat(temp, command[i+2]);
            
            // flags.push_back(temp);
            temp = "";
        }
    }

    // No flags found
    // if(flags.size() == 0) {
    //     flags.push_back("NOFLAGS");
    // }

    return flags;
}

// Returns a string containing the argument relative to the passed flag
void getArgument(char* dest, const char* command, const char* flag) {
    char temp[2];
    int count = 0;
    int pos;

    // Finds the position (of the first char) of the first occurrence of 'flag'
    for(int i = 0; i < strlen(command) - strlen(flag); i++) {
        for(int j = i, k = 0; j < strlen(flag); j++, k++) {
            if(command[j] == flag[k]) {
                count++;
            }

            if(count == strlen(flag)) pos = j - strlen(flag);
        }

        count = 0;
    }

    for(int i = pos + strlen(flag) + 1; command[i] != ' ' && command[i] != '\0'; i++) {
        charToString(temp, command[i]);
        strcat(dest, temp);
    }
}