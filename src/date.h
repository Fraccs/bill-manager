/*============================================================================
 * Name        : date.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 27/02/2022
 * Description : Header file containing date related functions declarations 
 *============================================================================*/

#ifndef _DATE_H
#define _DATE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define DDAT_MAXLEN 10
#define PDAT_MAXLEN 10

// Returns the current machine year
int dateYear();

// Returns the current machine month
int dateMonth();

// Returns the current machine day
int dateDay();

/* Formats dest with the current machine time in YYYY-MM-DD format
(dest_s is the size of dest excluding the additional NULL terminating character '\0')*/
int dateDayAccurate(char *dest, size_t dest_s);

/* Formats dest with the current machine time in YYYY-MM-DD.HH:mm:ss format
(dest_s is the size of dest excluding the additional NULL terminating character '\0')*/
int dateSecAccurate(char *dest, size_t dest_s);

// Returns the time since the Epoch (seconds)
char *dateEpochSeconds();

// Returns if the passed date respects the YYYY-MM-DD format
bool dateValidFormat(const char *date);

#endif