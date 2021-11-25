/*============================================================================
 * Name        : bill.cpp
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 25/11/2021
 * Description : Source file containing bill.h classes and functions bodies
 *============================================================================*/

#include "bill.h"

// ----- class Bill ----- //

Bill::Bill() {
    this->paid = false;
    this->cost = 0;
    this->usage = 0;
}

Bill::Bill(bool paid, float cost, float usage, int day, int month, int year) {
    if(cost <= 0) throw NEGATIVE_COST;
    if(usage <= 0) throw NEGATIVE_USAGE;

    try {
        due_date.setDay(day);
        due_date.setMonth(month);
        due_date.setYear(year);
    }
    catch(const std::string err) {
        throw err;
    }
    
    this->paid = paid;
    this->cost = cost;
    this->usage = usage;
}

Bill::Bill(bool paid, float cost, float usage) {
    if(cost <= 0) throw NEGATIVE_COST;
    if(usage <= 0) throw NEGATIVE_USAGE;

    this->paid = paid;
    this->cost = cost;
    this->usage = usage;
}

Bill::Bill(const Bill &bill) {
    this->cost = bill.cost;
    this->usage = bill.usage;
    this->paid = bill.paid;
}

Bill::~Bill() {}

// Set Bill::cost, throwing (const std::string)
void Bill::setCost(float cost) {
    if(cost <= 0) throw NEGATIVE_COST;

    this->cost = cost;
}

// Set Bill::due_date
void Bill::setDueDate(int day, int month, int year) {
    try {
        this->due_date.setDay(day);
        this->due_date.setMonth(month);
        this->due_date.setYear(year);
    }
    catch(const std::string err) {
        throw err;
    }
} 

// Set Bill::due_date
void Bill::setDueDate(Date due_date) {
    this->due_date = due_date;
}

// Set Bill::paid_date
void Bill::setPaidDate(int day, int month, int year) {
    try {
        this->paid_date.setDay(day);
        this->paid_date.setMonth(month);
        this->paid_date.setYear(year);
    }
    catch(const std::string err) {
        throw err;
    }
} 

// Set Bill::paid_date
void Bill::setPaidDate(Date paid_date) {
    this->paid_date = paid_date;
}

// Get Bill::cost (const float reference)
inline const float& Bill::getCost() const {return this->cost;}

// Get Bill::due_date (std::string)
inline const Date& Bill::getDueDate() const {return this->due_date;}    