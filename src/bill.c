/*============================================================================
 * Name        : bill.c
 * Version     : v1.0.0
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 19/04/2022
 * Description : Source file containing bill module structs and functions definitions
 *============================================================================*/

#include "bill.h"

/* bill type (incomplete declaration of struct bs).
Note that this is an opaque type and only pointer declaration is valid,
use the predefined functions to access members */
typedef struct bs {
    char type[TYPE_MAXLEN + 1];
    char due_date[DDAT_MAXLEN + 1];
    char paid_date[PDAT_MAXLEN + 1];
    bool paid;
    float cost;
} bill;

// Returns a pointer to the memory allocated for a struct bs
bill *billCreate() {
    bill *b = malloc(sizeof(bill));

    if(b == NULL) return NULL;

    /* ---- Initialization ---- */
    memset(b->type, 0, TYPE_MAXLEN + 1);
    memset(b->due_date, 0, DDAT_MAXLEN + 1);
    memset(b->paid_date, 0, PDAT_MAXLEN + 1);
    b->paid = false;
    b->cost = 0;

    return b;
}

// Destroys the passed bill (calls free() on the allocated memory)
int billDestroy(bill *b) {
    if(b == NULL) return -1;

    free(b);

    return 0;
}

// Set the type of the passed bill
int billSetType(bill *b, const char *type) {
    if(strlen(type) > 20) return -1;

    strncpy(b->type, type, TYPE_MAXLEN);

    return 0;
}

/* Set the type of date defined by format
(format="d": set bill->due_date, format="p": set bill->paid_date) */
int billSetDate(bill *b, const char *due_date, const char *format) {
    if(!dateValidFormat(due_date)) {
        return -1;
    }

    if(strcmp(format, "d") == 0) {
        strncpy(b->due_date, due_date, DDAT_MAXLEN);
        return 0;
    }
    
    if(strcmp(format, "p") == 0) {
        strncpy(b->paid_date, due_date, PDAT_MAXLEN);
        b->paid = true;
        return 0;
    }

    return -1;
}

// Set if the passed bill was paid or not
int billSetPaid(bill *b, bool paid) {
    if(b->paid == paid) {
        return -1;
    }

    b->paid = paid;

    return 0;
}

// Set the cost of the passed bill
int billSetCost(bill *b, float cost) {
    if(cost <= 0) return -1;

    b->cost = cost;

    return 0;
}

// Returns the type of the passed bill
char *billGetType(bill *b) {
    if(b == NULL) return NULL;

    return b->type;
}

/* Returns the type of date defined by format
(format="d": get bill->due_date, format="p": get bill->paid_date) */
char *billGetDate(bill *b, const char *format) {
    if(b == NULL || format == NULL) return NULL;

    if(strcmp(format, "d") == 0) {
        return b->due_date;
    }

    if(strcmp(format, "p") == 0) {
        return b->paid_date;
    }

    return NULL;
}

// Returns if the passed bill was paid
int billGetPaid(bill *b) {
    if(b == NULL) return -1;
    
    return b->paid; 
}

// Returns the cost of the passed bill
float billGetCost(bill *b) {
    if(b == NULL) return -1;

    return b->cost;
}

// Adds the passed bill to the bill list
int billAdd(bill *b) {
    FILE *f_handle;
    char path[PATH_MAXLEN + 1];

    memset(path, 0, PATH_MAXLEN + 1);

    /* ---- File path ---- */
    strncat(path, "data/", PATH_MAXLEN); // data/ 
    strncat(path, dateEpochSeconds(), PATH_MAXLEN); // data/file_name
    strncat(path, ".txt", PATH_MAXLEN); // data/file_name.txt

    /* ---- Writing onto the file ---- */
    f_handle = fopen(path, "a");
    
    if(f_handle == NULL) return -1;
    
    fprintf(f_handle, "Type: %s\n", billGetType(b));
    fprintf(f_handle, "Cost: %f\n", billGetCost(b));

    if(billGetPaid(b)) {
        fprintf(f_handle, "Paid: True\n");
    }
    else {
        fprintf(f_handle, "Paid: False\n");
    }

    fprintf(f_handle, "Paid in: %s\n", billGetDate(b, "p"));
    fprintf(f_handle, "Due date: %s\n", billGetDate(b, "d"));
   
    fclose(f_handle);

    return 0;
}

// Deletes the passed bill from the bill list
int billDelete(const char *file_name) {
    char path[PATH_MAXLEN + 1];
    int ret; // Error checking

    memset(path, 0, PATH_MAXLEN + 1);

    /* ---- File path ---- */
    strncat(path, "data/", PATH_MAXLEN); // data/ 
    strncat(path, file_name, PATH_MAXLEN); // data/file_name
    strncat(path, ".txt", PATH_MAXLEN); // data/file_name.txt

    ret = remove(path);

    if(ret == -1) return ret;

    return 0;
}

// Prints the content of a bill
int billView(const char *file_name) {
    FILE *f_handle;
    char line[101];
    char path[PATH_MAXLEN + 1];

    memset(line, 0, 101);
    memset(path, 0, PATH_MAXLEN + 1);

    /* ---- Path creation ---- */
    strncat(path, "data/", PATH_MAXLEN); // data/
    strncat(path, file_name, PATH_MAXLEN);  // data/FILE_NAME
    strncat(path, ".txt", PATH_MAXLEN);  // data/FILE_NAME.txt

    f_handle = fopen(path, "r");

    if(f_handle == NULL) return -1; // File not found

    /* ---- Print content ---- */
    while(fgets(line, 100, f_handle)) {
        printf("%s", line);
    }   

    return 0; 
}