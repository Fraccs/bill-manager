/*============================================================================
 * Name        : bill.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 27/02/2022
 * Description : Header file containing bill related structs and functions declarations
 *============================================================================*/

#ifndef _BILL_H
#define _BILL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "date.h"

#define TYPE_MAXLEN 20

/* Bill struct, note that this is an opaque type and only pointer declaration is valid.
Use the predefined functions to access members*/
typedef struct bs bill;

// Returns a pointer to the memory allocated on the heap for a new bill
bill *billCreate();

// Frees the memory of the passed bill
int billDestroy(bill *b);

// Set the type of a bill
int billSetType(bill *b, const char *type);

// Set the due date of a bill (format="d": due_date, format="p": paid_date)
int billSetDate(bill *b, const char *due_date, const char *format);

// Set if the bill was paid or not
int billSetPaid(bill *b, bool paid);

// Set the cost of a bill
int billSetCost(bill *b, float cost);

// Returns the type of the passed bill
char *billGetType(bill *b);

// Returns the due_date of the passed bill
char *billGetDueDate(bill *b);

// Returns the paid_date of the passed bill
char *billGetPaidDate(bill *b);

// Returns if the passed bill was paid
int billGetPaid(bill *b);

// Returns the cost of the passed bill
float billGetCost(bill *b); 

#endif