/*============================================================================
 * Name        : date.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 16/02/2022
 * Description : Header file containing date related functions declarations 
 *============================================================================*/

#ifndef _DATE_H
#define _DATE_H

#include <stdio.h>
#include <stdbool.h>
#include <time.h>

// Returns the current machine year
int currentMachineYear();

//Returns the current machine month
int currentMachineMonth();

//Returns the current machine day
int currentMachineDay();

// Returns the current machine time in YYYY-MM-DD format (char*)
char* machineTimeDayAccurate();

// Returns the current machine time in YYYY-MM-DD.HH:mm:ss format (char*)
char* machineTimeSecAccurate();

// Returns if the passed date respects the YYYY-MM-DD format
bool valid_format(char* date);

#endif