/*============================================================================
 * Name        : bill.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 23/11/2021
 * Description : Header containing "Bill" classes and functions prototypes
 *============================================================================*/

#ifndef _BILL_H
#define _BILL_H

#include <iostream>
#include <vector>
#include "date.h"
#include "logs.h"

// Base class for any type of Bill
// It also contains the exception strings
class Bill {
    protected:
    float cost;
    bool paid;
    
    // Due date for the payment of the bill 
    Date due_date;
    
    // Exception strings
    const std::string NEGATIVE_COST = "Exception handled: Negative cost."; 
    const std::string NEGATIVE_USAGE = "Exception handled: Negative usage.";

    public:
    ~Bill();

    // Set Bill::cost, throwing (const std::string)
    void setCost(float cost);

    // Set Bill::due_date       
    void setDueDate(int day, int month, int year);   

    // Get Bill::cost (const float reference)
    inline const float& getCost() const;
};

// Electrical bill
class ElectricalBill : public Bill {
    private:
    float electrical_usage;

    public:
    ElectricalBill();

    ElectricalBill(bool paid, float cost, float electrical_usage, int day, int month, int year);
};

// Gas bill
class GasBill : public Bill {
    private:
    float gas_usage;

    public:
    GasBill();

    GasBill(bool paid, float cost, float gas_usage, int day, int month, int year);
};

// Water bill
class WaterBill : public Bill {
    private:
    float water_usage;

    public:
    WaterBill();

    WaterBill(bool paid, float cost, float water_usage, int day, int month, int year);
};

// Phone bill
class PhoneBill : public Bill {
    public:
    PhoneBill();

    PhoneBill(bool paid, float cost, int day, int month, int year);
};

#endif