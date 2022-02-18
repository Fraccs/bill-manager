/*============================================================================
 * Name        : command_interpreter.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 18/02/2022
 * Description : Header file containing commandline-interface functions declarations
 *============================================================================*/

#ifndef _COMMAND_INTERPRETER_H
#define _COMMAND_INTERPRETER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "utils.h"

// Returns if the command starts with "bill"
bool startsWithBill(const char*);

// Returns the main flag of the passed command ("--example")
void findMainFlag(char*, const char*, size_t);

// Returns a vector containing all the flags of the passed command ("-a", "-b", ...)
char** findFlags(char*);

// Returns a string containing the argument relative to the passed flag
void getArgument(char*, const char*, const char*);

#endif