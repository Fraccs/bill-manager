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

#endif