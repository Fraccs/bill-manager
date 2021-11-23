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


// ----- class ElectricalBill ----- //

ElectricalBill::ElectricalBill() {
    this->paid = false;
    this->cost = 0;
    this->electrical_usage = 0;
}

ElectricalBill::ElectricalBill(bool paid, float cost, float electrical_usage, int day, int month, int year) {
    if(cost <= 0) throw NEGATIVE_COST;
    if(electrical_usage) throw NEGATIVE_USAGE;
    
    try {
        due_date.setDay(day);
        due_date.setMonth(month);
        due_date.setYear(year);
    }
    catch(const std::string err) {
        logToTxt("logs.txt", err);
    }

    this->paid = paid;
    this->cost = cost;
    this->electrical_usage = electrical_usage;
}


// ----- class GasBill ----- //

GasBill::GasBill() {
    this->paid = false;
    this->cost = 0;
    this->gas_usage = 0;
}

GasBill::GasBill(bool paid, float cost, float gas_usage, int day, int month, int year) {
    if(cost <= 0) throw NEGATIVE_COST;
    if(gas_usage) throw NEGATIVE_USAGE;

    try {
        due_date.setDay(day);
        due_date.setMonth(month);
        due_date.setYear(year);
    }
    catch(const std::string err) {
        logToTxt("logs.txt", err);
    }

    this->paid = paid;
    this->cost = cost;
    this->gas_usage = gas_usage;
}


// ----- class WaterBill ----- //

WaterBill::WaterBill() {
    this->paid = false;
    this->cost = 0;
    this->water_usage = 0;
}

WaterBill::WaterBill(bool paid, float cost, float water_usage, int day, int month, int year) {
    if(cost <= 0) throw NEGATIVE_COST;
    if(water_usage) throw NEGATIVE_USAGE;

    try {
        due_date.setDay(day);
        due_date.setMonth(month);
        due_date.setYear(year);
    }
    catch(const std::string err) {
        logToTxt("logs.txt", err);
    }

    this->paid = paid;
    this->cost = cost;
    this->water_usage = water_usage;
}


// ----- class PhoneBill ----- //

PhoneBill::PhoneBill() {
    this->paid = false;
    this->cost = 0;
}

PhoneBill::PhoneBill(bool paid, float cost, int day, int month, int year) {
    if(cost <= 0) throw NEGATIVE_COST;

    try {
        due_date.setDay(day);
        due_date.setMonth(month);
        due_date.setYear(year);
    }
    catch(const std::string err) {
        logToTxt("logs.txt", err);
    }

    this->paid = paid;
    this->cost = cost;
}
