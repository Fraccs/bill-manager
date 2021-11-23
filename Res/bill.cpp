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


ElectricalBill::ElectricalBill() {
    this->cost = 1;
    this->electrical_usage = 0;
}

ElectricalBill::ElectricalBill(float cost, float electrical_usage, int day, int month, int year) {
    if(cost <= 0) throw NEGATIVE_COST;
    if(electrical_usage) throw NEGATIVE_USAGE;
    // Code for due_date

    this->cost = cost;
    this->electrical_usage = electrical_usage;
    // Code for due_date
}

GasBill::GasBill() {
    this->cost = 1;
    this->gas_usage = 0;
    // Code for due_date
}

GasBill::GasBill(float cost, float gas_usage, int day, int month, int year) {
    if(cost <= 0) throw NEGATIVE_COST;
    if(gas_usage) throw NEGATIVE_USAGE;
    // Code for due_date

    this->cost = cost;
    this->gas_usage = gas_usage;
    // Code for due_date
}

PhoneBill::PhoneBill() {
    this->cost = 0;
    // Code for due_date
}

PhoneBill::PhoneBill(float cost, float electrical_usage, int day, int month, int year) {
    if(cost <= 0) throw NEGATIVE_COST;
    if(electrical_usage) throw NEGATIVE_USAGE;
    // Code for due_date

    this->cost = cost;
    // Code for due_date
}