/*============================================================================
 * Name        : command_interpreter.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 20/02/2022
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
bool startsWithBill(const char* command);

// Returns the main flag of the passed command ("--example")
int findMainFlag(char* dest, const char* command, size_t dest_s);

// Loads dest with all the flags of the passed command ("-a", "-b", ...), except for the main flag
void findFlags(char* dest[], const char* command);

// Returns a string containing the argument relative to the passed flag
int getArgument(char* dest, const char* command, const char* flag, size_t dest_s);

#endif