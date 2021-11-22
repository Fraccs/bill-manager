/*============================================================================
 * Name        : bill.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 22/11/2021
 * Description : Header containing "Bill" classes and sub classes 
 *============================================================================*/

#pragma once

#include <iostream>
#include <vector>
#include "date.h"
#include "logs.h"

// Base class for any type of Bill
// It also contains the exception strings
class Bill {
    protected:
    float cost;
    bool paid; // If it was paid or not
    
    // Due date for the payment of the bill 
    Date due_date;
    
    // Exception strings
    const std::string NEGATIVE_COST = "Exception handled: Negative cost."; 
    const std::string NEGATIVE_USAGE = "Exception handled: Negative usage.";

    public:
    // Set Bill::cost, throwing (const std::string)
    void setCost(float cost) {
        if(cost <= 0) throw NEGATIVE_COST;

        this->cost = cost;
    }

    // Set Bill::due_date       
    void setDueDate(int day, int month, int year) {
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
    inline const float& getCost() const {return this->cost;}
};


// Electrical bill
class ElectricalBill : public Bill {
    private:
    float electrical_usage;

    public:
    ElectricalBill() {
        this->cost = 1;
        this->electrical_usage = 0;
    }

    ElectricalBill(float cost, float electrical_usage, int day, int month, int year) {
        if(cost <= 0) throw NEGATIVE_COST;
        if(electrical_usage) throw NEGATIVE_USAGE;
        // Code for due_date

        this->cost = cost;
        this->electrical_usage = electrical_usage;
        // Code for due_date
    }
};


class GasBill : public Bill {
    private:
    float gas_usage;

    public:
    GasBill() {
        this->cost = 1;
        this->gas_usage = 0;
        // Code for due_date
    }

    GasBill(float cost, float gas_usage, int day, int month, int year) {
        if(cost <= 0) throw NEGATIVE_COST;
        if(gas_usage) throw NEGATIVE_USAGE;
        // Code for due_date

        this->cost = cost;
        this->gas_usage = gas_usage;
        // Code for due_date
    }
};


class PhoneBill : public Bill {
    public:
    PhoneBill() {
        this->cost = 0;
        // Code for due_date
    }

    PhoneBill(float cost, float electrical_usage, int day, int month, int year) {
        if(cost <= 0) throw NEGATIVE_COST;
        if(electrical_usage) throw NEGATIVE_USAGE;
        // Code for due_date

        this->cost = cost;
        // Code for due_date
    }
};