/*============================================================================
 * Name        : cli.h
 * Version     : v1.0.0
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 19/04/2022
 * Description : Header file containing commandline-interface functions declarations
 *============================================================================*/

#ifndef _COMMAND_INTERPRETER_H
#define _COMMAND_INTERPRETER_H

/* ---- Headers ---- */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "utils.h"

/* ---- Constants ---- */
#define COMM_MAXLEN 80
#define MNFG_MAXLEN 20
#define ARGM_MAXLEN 30
#define SUBFLAG_LEN 2

/* Loads dest with the entire commandline command ("billman --example -e 999") */
int cliExtractCommand(char *dest, int argc, char *argv[]);

/* Loads dest with the main flag of the passed command ("--example")
(dest_s is the size of dest excluding the additional NULL terminating character '\0')*/
int cliGetMainFlag(char *dest, const char *command, size_t dest_s);

/* Loads dest with the subflags of the passed command ex:("-a", "-b", ...) and
returns the number of subflags found in the command */
size_t cliGetSubFlags(char ***dest, const char *command);

/* Loads dest with the argument relative to the passed flag
(dest_s is the size of dest excluding the additional NULL terminating character '\0')*/
int cliGetArgument(char *dest, const char *command, const char *flag, size_t dest_s);

#endif