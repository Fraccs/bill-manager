/*============================================================================
 * Name        : command_interpreter.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 14/02/2022
 * Description : Header containing commandline interface functions declarations
 *============================================================================*/

#ifndef _COMMAND_INTERPRETER_H
#define _COMMAND_INTERPRETER_H

#include <stdio.h>
#include <stdbool.h>

// Returns if the command starts with "bill"
bool starts_with_bill(char* command);

// Returns the flags of the passed command ('--example')
char* find_main_flag(char* command);

// Returns a vector containing all the flags of the passed command
char** find_flags(char* command);

// Returns a string containing the argument relative to the passed flag
char* get_argument(char* command, char* flag);

#endif