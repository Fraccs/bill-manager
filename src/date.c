/*============================================================================
 * Name        : date.c
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 17/02/2022
 * Description : Source file containing date related functions definitions
 *============================================================================*/

#include "date.h"

// Returns the current machine year
int currentMachineYear() {
    time_t year = time(NULL);
    struct tm* ts = localtime(&year);

    return 1900 + ts->tm_year;
}

// Returns the current machine month
int currentMachineMonth() {
    time_t month = time(NULL);
    struct tm* ts = localtime(&month);
    
    return 1 + ts->tm_mon;
}

// Returns the current machine day
int currentMachineDay() {
    time_t day = time(NULL);
    struct tm *ts = localtime(&day);

    return ts->tm_mday;
}

// Formats dest with the current machine time in YYYY-MM-DD format
void machineTimeDayAccurate(char* dest) {
    time_t pc_time = time(NULL);
    struct tm tstruct = *localtime(&pc_time);

    strftime(dest, 11, "%Y-%m-%d", &tstruct);
}

// Formats dest with the current machine time in YYYY-MM-DD.HH:mm:ss format
void machineTimeSecAccurate(char* dest) {
    time_t pc_time = time(NULL);
    struct tm tstruct = *localtime(&pc_time);

    strftime(dest, 20, "%Y-%m-%d.%X", &tstruct);
}

// Returns if the passed date respects the YYYY-MM-DD format
bool valid_format(char* date) {
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