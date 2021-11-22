/*============================================================================
 * Name        : date.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 22/11/2021
 * Description : Header containing date related classes and functions 
 *============================================================================*/

#pragma once

#include <ctime>
#include <string>

// Returns the current machine year
const int currentMachineYear() {
    std::time_t year = time(0);
    std::tm *ts = localtime(&year);
    const int current_year = 1900 + ts->tm_year;

    return current_year;
}

// Returns the current machine month
const int currentMachineMonth() {
    std::time_t month = time(0);
    std::tm *ts = localtime(&month);
    const int current_month = 1 + ts->tm_mon;

    return current_month;
}

// Returns the current machine day
const int currentMachineDay() {
    std::time_t day = time(0);
    std::tm *ts = localtime(&day);
    const int current_day = ts->tm_mday;

    return current_day;
}

// Returns the current machine time in YYYY-MM-DD.HH:mm:ss format (std::string)
const std::string currentMachineTime() {
    std::time_t machine_time = time(0);
    std::tm tstruct = *localtime(&machine_time);
    char formatted_time[80];

    // Formatting to a time string
    strftime(formatted_time, sizeof(formatted_time), "%Y-%m-%d.%X", &tstruct);

    return formatted_time;
}

// Base class for Date
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
    Date() {
        this->day = currentMachineDay();
        this->month = currentMachineMonth();
        this->year = currentMachineYear();
    }

    Date(int day, int month, int year) {
        if(day < 1 || day > 31) throw INVALID_DAY;
        if(month < 1 || month > 12) throw INVALID_MONTH;
        if(year < 1900 || year > currentMachineYear()) throw INVALID_YEAR;

        this->day = day;
        this->month = month;
        this->year = year;
    }

    Date(const Date &date) {
        this->day = date.day;
        this->month = date.month;
        this->year = date.year;
    }

    ~Date() {}
    
    // Set Date::day, throwing (const std::string)
    void setDay(int day) {
        if(day < 1 || day > 31) throw INVALID_DAY;

        this->day = day;
    }

    // Set Date::month, throwing (const std::string)
    void setMonth(int month) {
        if(month < 1 || month > 12) throw INVALID_MONTH;

        this->month = month;
    }

    // Set Date::year, throwing (const std::string)
    void setYear(int year) {
        if(year < 1900 || year > currentMachineYear()) throw INVALID_YEAR;

        this->year = year;
    }

    // Get Date::day (const int reference)
    inline const int& getDay() const {return this->day;}
    // Get Date::month (const int reference)
    inline const int& getMonth() const {return this->month;}
    // Get Date::year (const int reference)
    inline const int& getYear() const {return this->year;}

    // Returns the date in YYYY-MM-DD format (std::string)
    const std::string getDate() {
        return std::to_string(this->year)  + "-" + std::to_string(this->month) + "-" + std::to_string(this->day);
    }
};