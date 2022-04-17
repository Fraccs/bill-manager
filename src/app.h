/*============================================================================
 * Name        : app.h
 * Version     : v1.0.0
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 17/04/2022
 * Description : Header file containing app module functions declarations
 *============================================================================*/

#ifndef _APP_H
#define _APP_H

/* ---- Headers ---- */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/stat.h>
#endif

#include "cli.h"
#include "client.h"
#include "bill.h"
#include "echo.h"
#include "help.h"
#include "logs.h"
#include "utils.h"

/* ---- Constants ---- */
#define COMM_MAXLEN 80
#define MNFG_MAXLEN 20
#define ARGM_MAXLEN 30

// Main function
int startApplication(int argc, char *argv[]);

#endif