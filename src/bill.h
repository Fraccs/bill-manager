/*============================================================================
 * Name        : bill.h
 * Version     : v1.0.0
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 19/04/2022
 * Description : Header file containing bill module structs and functions declarations
 *============================================================================*/

#ifndef _BILL_H
#define _BILL_H

/* ---- Headers ---- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#include "date.h"

/* ---- Constants ----- */
#define TYPE_MAXLEN 20 // bs->type max length
#define PATH_MAXLEN 19

/* bill type (incomplete declaration of struct bs).
Note that this is an opaque type and only pointer declaration is valid,
use the predefined functions to access members */
typedef struct bs bill;

// Returns a pointer to the memory allocated for a struct bs
bill *billCreate();

// Destroys the passed bill (calls free() on the allocated memory)
int billDestroy(bill *b);

// Set the type of the passed bill
int billSetType(bill *b, const char *type);

/* Set the type of date defined by format
(format="d": set bill->due_date, format="p": set bill->paid_date) */
int billSetDate(bill *b, const char *due_date, const char *format);

// Set if the passed bill was paid or not
int billSetPaid(bill *b, bool paid);

// Set the cost of the passed bill
int billSetCost(bill *b, float cost);

// Returns the type of the passed bill
char *billGetType(bill *b);

/* Returns the type of date defined by format
(format="d": get bill->due_date, format="p": get bill->paid_date) */
char *billGetDate(bill *b, const char *format);

// Returns if the passed bill was paid
int billGetPaid(bill *b);

// Returns the cost of the passed bill
float billGetCost(bill *b); 

// Adds the passed bill to the bill list
int billAdd(bill *b);

// Deletes the passed bill from the bill list
int billDelete(const char *file_name);

// Prints the content of a bill
int billView(const char *file_name);

// Prints the list of bills
int billViewAll();

#endif