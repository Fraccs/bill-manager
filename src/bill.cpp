/*============================================================================
 * Name        : bill.cpp
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 12/02/2022
 * Description : Source file containing bill.hpp classes and functions definitions
 *============================================================================*/

#include "bill.hpp"

// ----- class Bill ----- //

Bill::Bill() {
    this->paid = false;
    this->type = "Generic";
    this->cost = 0;
    this->usage = 0;
    this->paid_date = "N/D";
    this->due_date = machineTimeDayAccurate();
}

Bill::Bill(const Bill &bill) {
    this->paid = bill.paid;
    this->type = bill.type;
    this->cost = bill.cost;
    this->usage = bill.usage;
    this->due_date = bill.due_date;
    this->paid_date = bill.paid_date;
}

Bill::~Bill() {}

// Set Bill::type
void Bill::setType(std::string type) {
    this->type = type;
}

// Set Bill::cost, throwing (const std::string)
void Bill::setCost(float cost) {
    if(cost <= 0) throw NEGATIVE_COST;

    this->cost = cost;
}

// Set Bill::usage, throwing (const std::string)
void Bill::setUsage(float usage) {
    if(usage <= 0) throw NEGATIVE_USAGE;

    this->usage = usage;
}

// Set Bill::paid to true
void Bill::setPaid() {
    this->paid = true;
} 

// Set Bill::due_date, throwing (const std::string)     
void Bill::setDueDate(std::string due_date) {
    if(!valid_format(due_date)) throw "'" + due_date + "' does not respect the YYYY-MM-DD format."; 

    this->due_date = due_date;
}

// Set Bill::paid_date, throwing (const std::string)
void Bill::setPaidDate(std::string paid_date) {
    if(!valid_format(paid_date)) throw "'" + paid_date + "' does not respect the YYYY-MM-DD format."; 
    if(paid_date > machineTimeDayAccurate()) throw "'" + paid_date + "' hasn't come yet.";

    this->paid_date = paid_date;
}

// Get Bill::type (const std::string)
const std::string Bill::getType() const {return this->type;}

// Get Bill::cost (const float reference)
const float& Bill::getCost() const {return this->cost;}

// Get Bill::usage (const float reference)
const float& Bill::getUsage() const {return this->usage;} 

// Get Bill::paid (const bool reference)
const bool& Bill::getPaid() const {return this->paid;}

// Get Bill::paid_date (const std::string reference)
const std::string& Bill::getPaidDate() const {return this->paid_date;}

// Get Bill::due_date (const std::string reference)
const std::string& Bill::getDueDate() const {return this->due_date;}