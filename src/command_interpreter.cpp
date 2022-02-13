/*============================================================================
 * Name        : command_interpreter.cpp
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 12/02/2022
 * Description : Source file containing command_interpreter.h functions definitions
 *============================================================================*/

#include "command_interpreter.hpp"

// Returns if the command starts with "bill"
bool starts_with_bill(std::string command) {
    if(command[0] != 'b') return false;
    if(command[1] != 'i') return false;
    if(command[2] != 'l') return false;
    if(command[3] != 'l') return false;
    if(command[4] != ' ') return false;

    return true;
}

// Returns the flags of the passed command ('--example')
std::string find_main_flag(std::string command) {
    std::string temp = "";

    for(int i = 0; i < command.size(); i++) {
        if(command[i] == ' ' && command[i+1] == '-' && command[i+2] == '-') {
            for(int j = i + 1; command[j] != ' ' && command[j] != '\0'; j++) {
                temp.push_back(command[j]);
            }    
        }
    }

    return temp;
}

// Returns a vector containing all the flags of the passed command
std::vector<std::string> find_flags(std::string command) {
    std::vector<std::string> flags;
    std::string temp = "";

    // Adding a space to the end, otherwise flags at the end wouldn't work
    command.push_back(' ');

    for(int i = 0; i < command.size() - 3; i++) {
        if(command[i] == ' ' && command[i+1] == '-' && command[i+3] == ' ') {
            temp.push_back(command[i+1]);
            temp.push_back(command[i+2]);

            flags.push_back(temp);
            temp = "";
        }
    }

    // No flags found
    if(flags.size() == 0) {
        flags.push_back("NOFLAGS");
    }

    return flags;
}

// Returns a string containing the argument relative to the passed flag
std::string get_argument(std::string command, std::string flag) {
    std::string arg;

    for(int i = command.find(flag) + flag.size() + 1; command[i] != ' ' && command[i] != '\0'; i++) {
        arg.push_back(command[i]);
    }

    return arg;
}