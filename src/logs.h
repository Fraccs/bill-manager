/*============================================================================
 * Name        : logs.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 14/02/2022
 * Description : Header containing logs related functions declarations
 *============================================================================*/

#ifndef _LOGS_H
#define _LOGS_H

#include <stdio.h>
#include "date.h"

// Logs the passed string to a txt, keeping track of the current machine time
int logToTxt(char* file_name, char* str);

#endif