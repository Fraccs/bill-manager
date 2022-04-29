/*============================================================================
 * Name        : logs.h
 * Version     : v1.1.0
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 04/03/2022
 * Description : Header file containing logs related functions declarations
 *============================================================================*/

#ifndef _LOGS_H
#define _LOGS_H

/* ---- Headers ---- */
#include <stdio.h>

#include "date.h"

#define LOGS_MAXLEN 100

// Logs the passed string to a txt, keeping track of the current machine time
int logEvent(const char *logfile_name, const char *str);

#endif