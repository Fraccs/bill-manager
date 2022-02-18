/*============================================================================
 * Name        : client.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 18/02/2022
 * Description : Header file containing client related structs and functions declarations
 *============================================================================*/

#ifndef _CLIENT_H
#define _CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifndef _WIN32
#include <unistd.h>
#endif

#include "bill.h"

typedef struct {
    char* username;
    char* password;
    bool logged_in;
} client;

/* Checks if another istance of username exists, 
if it doesn't it saves the username and password in 'clients.txt'*/
int registerClient(client*, const char*, const char*);

/* Looks for username matches in 'clients.txt', 
if it finds one and the password is correct it logs-in the given client*/
int loginClient(client*, const char*, const char*);

// Logout from the current client
int logoutClient(client*);

// Adds the passed bill to the client's bill list
int addBill(client*, bill);

// Deletes all the bills of the logged client
void deleteAll(client*);

// Deletes the passed bill from the client's bill list
void deleteBill(client*, const char*);

// Deletes the logged client
void deleteClient(client*);

// Prints the bills that match the flags
void viewAll(client*);

// Prints the content of a bill
int viewBill(client*, const char*);

#endif