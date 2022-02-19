/*============================================================================
 * Name        : client.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 19/02/2022
 * Description : Header file containing client related structs and functions declarations
 *============================================================================*/

#ifndef _CLIENT_H
#define _CLIENT_H

#define USER_MAXLEN 10
#define PASS_MAXLEN 20

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
    char username[USER_MAXLEN + 1];
    char password[PASS_MAXLEN + 1];
    bool logged_in;
} client;

/* Checks if another instance of username exists, 
if it doesn't it saves the username and password in 'clients.txt'*/
int registerClient(client* c, const char* username, const char* password);

/* Looks for username matches in 'clients.txt', 
if it finds one and the password is correct it logs-in the given client*/
int loginClient(client* c, const char* username, const char* password);

// Logout from the current client
int logoutClient(client* c);

// Adds the passed bill to the client's bill list
int addBill(client* c, bill b);

// Deletes all the bills of the logged client
void deleteAll(client* c);

// Deletes the passed bill from the client's bill list
void deleteBill(client* c, const char* file_name);

// Deletes the logged client
// void deleteClient(client* c);

// Prints the bills that match the flags
void viewAll(client* c);

// Prints the content of a bill
int viewBill(client* c, const char* file_name);

#endif