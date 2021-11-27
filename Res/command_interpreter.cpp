/*============================================================================
 * Name        : command_interpreter.cpp
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 27/11/2021
 * Description : Source file containing command_interpreter.h functions definitions
 *============================================================================*/

#include "command_interpreter.h"

// Returns if the command starts with "bill"
bool starts_with_bill(std::string command) {
    if(command[0] != 'b') return false;
    if(command[1] != 'i') return false;
    if(command[2] != 'l') return false;
    if(command[3] != 'l') return false;
    if(command[4] != ' ') return false;

    return true;
}

// Returns the arguments of the passed command
std::vector<char> find_flags(std::string command) {
    std::vector<char> arguments;

    for(int i = 0; i < command.size() - 3; i++) {
        if(command[i] == ' ' && command[i+1] == '-' && command[i+3] == ' ') {
            arguments.push_back(command[i+2]);
        }
    }

    return arguments;
}

// Returns the arguments of the passed command
std::vector<std::string> find_flags(std::string command, int mode) {
    std::vector<std::string> arguments;
    std::string temp;

    for(int i = 0; i < command.size() - 3; i++) {
        if(command[i] == ' ' && command[i+1] == '-' && command[i+2] == '-' && (command[i+3] >= 'a' && command[i+3] <= 'z')) {
            for(int j = i + 3; command[j] != ' ' || command[j] != '\0'; j++) {
                temp.push_back(command[j]);
            }
        }

        arguments.push_back(temp);
    }

    return arguments;
}

// Returns an std::vector containing the arguments of the passed command
std::vector<std::string> parse_command(std::string command) {
    std::vector<std::string> temp;

    if(!starts_with_bill(command)) throw "Exception handled: command doesn't begin with 'bill'";

    return temp;
}