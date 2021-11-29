/*============================================================================
 * Name        : date.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 29/11/2021
 * Description : Header containing date related classes and functions prototypes 
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

// Base class for date
class Date {
    private:
    int day;
    int month;
    int year;

    // Exception strings
    const std::string INVALID_DAY = "Exception handled: Invalid day.";
    const std::string INVALID_MONTH = "Exception handled: Invalid month.";
    const std::string INVALID_YEAR = "Exception handled: Invalid year.";

    public:
    Date();
    Date(int day, int month, int year);  
    Date& operator=(const Date& date);
    ~Date();

    // Set Date::day, throwing (const std::string)
    void setDay(int day);
    // Set Date::month, throwing (const std::string)
    void setMonth(int month);
    // Set Date::year, throwing (const std::string)
    void setYear(int year);

    // Get Date::day (const int reference)
    const int& getDay() const;
    // Get Date::month (const int reference)
    const int& getMonth() const;
    // Get Date::year (const int reference)
    const int& getYear() const;

    // Returns the date in YYYY-MM-DD format (std::string)
    const std::string getDateInString();
};

#endif