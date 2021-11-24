/*============================================================================
 * Name        : bill.cpp
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 23/11/2021
 * Description : Source file containing bill.h classes and functions bodies
 *============================================================================*/

#include "bill.h"

// ----- class Bill ----- //

Bill::~Bill() {}

// Set Bill::cost, throwing (const std::string)
void Bill::setCost(float cost) {
    if(cost <= 0) throw NEGATIVE_COST;

    this->cost = cost;
}

// Set Bill::due_date
void Bill::setDueDate(int day, int month, int year) {
    try {
        due_date.setDay(day);
        due_date.setMonth(month);
        due_date.setYear(year);
    }
    catch(const std::string err) {
        logToTxt("logs.txt", err);
    }
} 

// Get Bill::cost (const float reference)
inline const float& Bill::getCost() const {return this->cost;}