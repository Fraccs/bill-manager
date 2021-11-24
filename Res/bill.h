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
    private:
    bool paid;
    float cost;
    float usage;
    
    // Due date for the payment of the bill 
    Date due_date;

    // The date the bill was paid at
    Date paid_date;

    // Exception strings
    const std::string NEGATIVE_COST = "Exception handled: Negative cost."; 
    const std::string NEGATIVE_USAGE = "Exception handled: Negative usage.";

    public:
    Bill();
    Bill(bool paid, float cost, float usage, int day, int month, int year);
    Bill(bool paid, float cost, float usage);
    Bill& operator = (const Bill& bill);
    Bill(const Bill &bill);
    ~Bill();

    // Set Bill::cost, throwing (const std::string)
    void setCost(float cost);

    // Set Bill::due_date       
    void setDueDate(int day, int month, int year);  

    // Set Bill::due_date
    void setDueDate(Date due_date);

    // Set Bill::paid_date
    void setPaidDate(int day, int month, int year);

    // Set Bill::paid_date
    void setPaidDate(Date due_date);

    // Get Bill::cost (const float reference)
    inline const float& getCost() const;

    // Get Bill::due_date (std::string)
    inline const Date& getDueDate() const;    

    // Returns if the bill was paid in time
    bool paidInTime();
};

#endif