/*============================================================================
 * Name        : app.h
 * Version     : v1.1.0
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 22/04/2022
 * Description : Header file containing app module functions declarations
 *============================================================================*/

#ifndef _APP_H
#define _APP_H

/* ---- Headers ---- */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

#include "cli.h"
#include "bill.h"
#include "help.h"
#include "logs.h"
#include "utils.h"

// Buffering setup
void initApplication();

// Program's core function
int startApplication(int argc, char *argv[]);

#endif