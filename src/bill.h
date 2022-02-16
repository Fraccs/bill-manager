/*============================================================================
 * Name        : bill.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 16/02/2022
 * Description : Header file containing bill related structs and functions declarations
 *============================================================================*/

#ifndef _BILL_H
#define _BILL_H

#include <stdio.h>

#include "date.h"

// Struct bill
typedef struct {
    char* type;
    char* due_date;
    char* paid_date;
    bool paid;
    float cost;
    float usage;
} bill;

#endif