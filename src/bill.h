/*============================================================================
 * Name        : bill.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 24/02/2022
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

/* Loads dest with the passed bill's type
(dest_s is the size of dest excluding the additional NULL terminating character '\0')*/
int billGetType(bill *b, char *dest, size_t dest_s);

/* Loads dest with the passed bill's due_date
(dest_s is the size of dest excluding the additional NULL terminating character '\0')*/
int billGetDueDate(bill *b, char *dest, size_t dest_s);

/* Loads dest with the passed bill's paid_date
(dest_s is the size of dest excluding the additional NULL terminating character '\0')*/
int billGetPaidDate(bill *b, char *dest, size_t dest_s);

// Returns if the passed bill was paid
int billGetPaid(bill *b);

// Returns the passed-bill's cost
float billGetCost(bill *b); 

#endif