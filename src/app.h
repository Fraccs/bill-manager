/*============================================================================
 * Name        : app.h
 * Version     : v1.0.0
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 18/04/2022
 * Description : Header file containing app module functions declarations
 *============================================================================*/

#ifndef _APP_H
#define _APP_H

/* ---- Headers ---- */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/stat.h>

#include "cli.h"
#include "bill.h"
#include "help.h"
#include "logs.h"
#include "utils.h"

// Main function
int startApplication(int argc, char *argv[]);

#endif