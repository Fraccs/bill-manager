/*============================================================================
 * Name        : command_interpreter.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 05/12/2021
 * Description : Header containing commandline interface functions declarations
 *============================================================================*/

#ifndef _COMMAND_INTERPRETER_H
#define _COMMAND_INTERPRETER_H

#include <iostream>
#include <vector>

// Returns if the command starts with "bill"
bool starts_with_bill(std::string command);

// Returns the flags of the passed command ('--example')
std::string find_main_flag(std::string command);

// Returns a vector containing all the flags of the passed command
std::vector<std::string> find_flags(std::string command);

// Returns a string containing the argument relative to the passed flag
std::string get_argument(std::string command, std::string flag);

#endif