/*============================================================================
 * Name        : command_interpreter.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 27/11/2021
 * Description : Header containing commandline interface functions
 *============================================================================*/

#ifndef _COMMAND_INTERPRETER_H
#define _COMMAND_INTERPRETER_H

#include <iostream>
#include <vector>

// Returns if the command starts with "bill"
bool starts_with_bill(std::string command);

// Returns an std::vector containing the arguments of the passed command
std::vector<std::string> parse_command(std::string command);

#endif