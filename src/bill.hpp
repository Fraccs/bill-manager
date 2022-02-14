/*============================================================================
 * Name        : bill.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 12/02/2022
 * Description : Header containing "Bill" classes and functions declarations
 *============================================================================*/

#ifndef _BILL_HPP
#define _BILL_HPP

#include <iostream>

#include "date.hpp"
#include "logs.hpp"

// Base class for any type of Bill
// It also contains the exception strings
class Bill {
    private:
    std::string type; // Water, Electricity, Phone...
    std::string due_date;
    std::string paid_date;
    bool paid;
    float cost;
    float usage;

    // Exception strings
    const std::string NEGATIVE_COST = "Exception handled: Negative cost."; 
    const std::string NEGATIVE_USAGE = "Exception handled: Negative usage.";

    public:
    Bill();
    Bill& operator = (const Bill& bill);
    Bill(const Bill &bill);
    ~Bill();

    // Set Bill::type
    void setType(std::string type);

    // Set Bill::cost, throwing (const std::string)
    void setCost(float cost);

    // Set Bill::usage, throwing (const std::string)
    void setUsage(float usage);

    // Set Bill::paid to true
    void setPaid();

    // Set Bill::due_date, throwing (const std::string)     
    void setDueDate(std::string date);

    // Set Bill::paid_date, throwing (const std::string)
    void setPaidDate(std::string date);

    // Get Bill::type (const std::string)
    const std::string getType() const;

    // Get Bill::cost (const float reference)
    const float& getCost() const;

    // Get Bill::usage (const float reference)
    const float& getUsage() const;

    // Get Bill::paid (const bool reference)
    const bool& getPaid() const;

    // Get Bill::paid_date (const std::string reference)
    const std::string& getPaidDate() const;
    
    // Get Bill::due_date (const std::string reference)
    const std::string& getDueDate() const;
};

#endif