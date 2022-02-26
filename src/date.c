/*============================================================================
 * Name        : date.c
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 26/02/2022
 * Description : Source file containing date related functions definitions
 *============================================================================*/

#include "date.h"

// Returns the current machine year
int dateYear() {
    time_t year = time(NULL);
    struct tm* ts = localtime(&year);

    return 1900 + ts->tm_year;
}

// Returns the current machine month
int dateMonth() {
    time_t month = time(NULL);
    struct tm* ts = localtime(&month);
    
    return 1 + ts->tm_mon;
}

// Returns the current machine day
int dateDay() {
    time_t day = time(NULL);
    struct tm *ts = localtime(&day);

    return ts->tm_mday;
}

/* Formats dest with the current machine time in YYYY-MM-DD format
(dest_s is the size of dest excluding the additional NULL terminating character '\0')*/
int dateDayAccurate(char *dest, size_t dest_s) {
    time_t pc_time = time(NULL);
    struct tm tstruct = *localtime(&pc_time);

    if(dest_s != 10) return -1;

    strftime(dest, dest_s + 1, "%Y-%m-%d", &tstruct);

    return 0;
}

/* Formats dest with the current machine time in YYYY-MM-DD.HH:mm:ss format
(dest_s is the size of dest excluding the additional NULL terminating character '\0')*/
int dateSecAccurate(char *dest, size_t dest_s) {
    time_t pc_time = time(NULL);
    struct tm tstruct = *localtime(&pc_time);

    if(dest_s != 19) return -1;

    strftime(dest, dest_s + 1, "%Y-%m-%d.%X", &tstruct);

    printf("%s\n", dest);

    return 0;
}

// Returns if the passed date respects the YYYY-MM-DD format
bool dateValidFormat(const char *date) {
    if(strlen(date) != 10) return false;
    if(date[4] != '-' || date[7] != '-') return false;

    for(int i = 0; i < strlen(date); i++) {
        if(date[i] < '0' || date[i] > '9') {
            if(date[i] != '-') {
                return false;
            }
        }
    }

    return true;
}