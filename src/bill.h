/*============================================================================
 * Name        : bill.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 22/02/2022
 * Description : Header file containing bill related structs and functions declarations
 *============================================================================*/

#ifndef _BILL_H
#define _BILL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "date.h"

#define TYPE_MAXLEN 20

// Struct bill
typedef struct bs bill;

// Returns a pointer to the memory allocated on the heap for a new bill
bill* billCreate();

// Frees the memory of the passed bill
void billDestroy(bill* b);

// Set the type of a bill
int bsetType(bill* b, const char* type);

// Set the due date of a bill (format="d": due_date, format="p": paid_date)
int bsetDate(bill* b, const char* due_date, const char* format);

// Set if the bill was paid or not
int bsetPaid(bill* b, bool paid);

// Set the cost of a bill
int bsetCost(bill* b, float cost);

#endif