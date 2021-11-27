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

// Returns an std::vector containing the arguments of the passed command
std::vector<std::string> parse_command(std::string command) {
    std::vector<std::string> temp;

    if(!starts_with_bill(command)) throw "Exception handled: command doesn't begin with 'bill'";

    return temp;
}