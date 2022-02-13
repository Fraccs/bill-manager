/*============================================================================
 * Name        : date.cpp
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 12/02/2022
 * Description : Source file containing date.hpp classes and functions definitions
 *============================================================================*/

#include "date.hpp"

// Returns the current machine year
const int currentMachineYear() {
    std::time_t year = time(nullptr);
    std::tm *ts = localtime(&year);

    return 1900 + ts->tm_year;
}

// Returns the current machine month
const int currentMachineMonth() {
    std::time_t month = time(nullptr);
    std::tm *ts = localtime(&month);
    
    return 1 + ts->tm_mon;
}

// Returns the current machine day
const int currentMachineDay() {
    std::time_t day = time(nullptr);
    std::tm *ts = localtime(&day);

    return ts->tm_mday;
}

// Returns the current machine time in YYYY-MM-DD format (std::string)
const std::string machineTimeDayAccurate() {
    std::time_t machine_time = time(0);
    std::tm tstruct = *localtime(&machine_time);
    char formatted_time[80];

    // Formatting to a time string
    strftime(formatted_time, sizeof(formatted_time), "%Y-%m-%d", &tstruct);

    return formatted_time;
}

// Returns the current machine time in YYYY-MM-DD.HH:mm:ss format (std::string)
const std::string machineTimeSecAccurate() {
    std::time_t machine_time = time(0);
    std::tm tstruct = *localtime(&machine_time);
    char formatted_time[80];

    // Formatting to a time string
    strftime(formatted_time, sizeof(formatted_time), "%Y-%m-%d.%X", &tstruct);

    return formatted_time;
}

// Returns if the passed date respects the YYYY-MM-DD format
bool valid_format(std::string date) {
    if(date.size() != 10) return false;
    if(date[4] != '-' || date[7] != '-') return false;

    for(int i = 0; i < date.size(); i++) {
        if(date[i] < '0' || date[i] > '9') {
            if(date[i] != '-') {
                return false;
            }
        }
    }

    return true;
}