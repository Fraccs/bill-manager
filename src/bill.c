/*============================================================================
 * Name        : bill.c
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 23/02/2022
 * Description : Source file containing bill related structs and functions definitions
 *============================================================================*/

#include "bill.h"

// Struct bill
typedef struct bs {
    char type[TYPE_MAXLEN + 1];
    char due_date[DDAT_MAXLEN + 1];
    char paid_date[PDAT_MAXLEN + 1];
    bool paid;
    float cost;
} bill;

// Returns a pointer to the memory allocated on the heap for a new bill
bill* billCreate() {
    bill* b = malloc(sizeof(bill));

    if(b == NULL) return NULL;

    memset(b->type, 0, TYPE_MAXLEN);
    memset(b->due_date, 0, DDAT_MAXLEN);
    memset(b->paid_date, 0, PDAT_MAXLEN);
    b->paid = false;
    b->cost = 0;

    return b;
}

// Frees the memory of the passed bill
int billDestroy(bill* b) {
    if(b == NULL) return -1;

    free(b);

    return 0;
}

// Set the type of a bill
int billSetType(bill* b, const char* type) {
    if(strlen(type) > 20) return -1;

    strncpy(b->type, type, TYPE_MAXLEN);

    return 0;
}

// Set the due date of a bill (format=d: due_date, format=p: paid_date)
int billSetDueDate(bill* b, const char* due_date, const char* format) {
    if(!dvalidFormat(due_date)) {
        return -1;
    }

    if(strcmp(format, "d")) {
        strncpy(b->due_date, due_date, DDAT_MAXLEN);
        return 0;
    }
    
    if(strcmp(format, "p")) {
        strncpy(b->paid_date, due_date, PDAT_MAXLEN);
        return 0;
    }

    return -1;
}

// Set if the bill was paid or not
int billSetPaid(bill* b, bool paid) {
    if(b->paid == paid) {
        return -1;
    }

    b->paid = paid;

    return 0;
}

// Set the cost of a bill
int billSetCost(bill* b, float cost) {
    if(cost <= 0) return -1;

    b->cost = cost;

    return 0;
}