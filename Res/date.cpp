/*============================================================================
 * Name        : date.cpp
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 29/11/2021
 * Description : Source file containing date.h classes and functions bodies
 *============================================================================*/

#include "date.h"

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

Date::Date() {
    this->day = currentMachineDay();
    this->month = currentMachineMonth();
    this->year = currentMachineYear();
}

Date::Date(int day, int month, int year) {
    if(day < 1 || day > 31) throw INVALID_DAY;
    if(month < 1 || month > 12) throw INVALID_MONTH;
    if(year < 1900 || year > currentMachineYear()) throw INVALID_YEAR;

    this->day = day;
    this->month = month;
    this->year = year;
}

Date& Date::operator=(const Date& date) {
    return *this;
}

Date::~Date() {}

// Set Date::day, throwing (const std::string)
void Date::setDay(int day) {
    if(day < 1 || day > 31) throw INVALID_DAY;

    this->day = day;
}

// Set Date::month, throwing (const std::string)
void Date::setMonth(int month) {
    if(month < 1 || month > 12) throw INVALID_MONTH;

    this->month = month;
}

// Set Date::year, throwing (const std::string)
void Date::setYear(int year) {
    if(year < 1900 || year > currentMachineYear()) throw INVALID_YEAR;

    this->year = year;
}

// Get Date::day (const int reference)
const int& Date::getDay() const {return this->day;}

// Get Date::month (const int reference)
const int& Date::getMonth() const {return this->month;}

// Get Date::year (const int reference)
const int& Date::getYear() const {return this->year;}

// Returns the date in YYYY-MM-DD format (std::string)
const std::string Date::getDateInString() {
    return std::to_string(this->year)  + "-" + std::to_string(this->month) + "-" + std::to_string(this->day);
}