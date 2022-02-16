/*============================================================================
 * Name        : command_interpreter.c
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 16/02/2022
 * Description : Source file containing commandline-interface functions definitions
 *============================================================================*/

#include "command_interpreter.h"

// Returns if the command starts with "bill"
bool startsWithBill(char* command) {
    if(command[0] != 'b') return false;
    if(command[1] != 'i') return false;
    if(command[2] != 'l') return false;
    if(command[3] != 'l') return false;
    if(command[4] != ' ') return false;

    return true;
}

// Returns the flags of the passed command ('--example')
char* findMainFlag(char* command) {
    char* temp = "";

    for(int i = 0; i < strlen(command); i++) {
        if(command[i] == ' ' && command[i+1] == '-' && command[i+2] == '-') {
            for(int j = i + 1; command[j] != ' ' && command[j] != '\0'; j++) {
                strcat(temp, command[j]);
            }    
        }
    }

    return temp;
}

// Returns a vector containing all the flags of the passed command
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
char* getArgument(char* command, char* flag) {
    char* arg;
    char* temp;
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
        temp = charToString(command[i]);
        strcat(arg, temp);
    }

    free(temp);

    return arg;
}