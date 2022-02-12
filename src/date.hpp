/*============================================================================
 * Name        : date.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 12/02/2022
 * Description : Header containing date related classes and functions declarations 
 *============================================================================*/

#ifndef _DATE_H
#define _DATE_H

#include <iostream>
#include <ctime>
#include <string>

// Returns the current machine year
const int currentMachineYear();

//Returns the current machine month
const int currentMachineMonth();

//Returns the current machine day
const int currentMachineDay();

// Returns the current machine time in YYYY-MM-DD format (std::string)
const std::string machineTimeDayAccurate();

// Returns the current machine time in YYYY-MM-DD.HH:mm:ss format (std::string)
const std::string machineTimeSecAccurate();

// Returns if the passed date respects the YYYY-MM-DD format
bool valid_format(std::string date);

#endif