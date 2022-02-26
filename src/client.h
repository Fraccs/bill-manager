/*============================================================================
 * Name        : client.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 26/02/2022
 * Description : Header file containing client related structs and functions declarations
 *============================================================================*/

#ifndef _CLIENT_H
#define _CLIENT_H

#define USER_MAXLEN 10
#define PASS_MAXLEN 20

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#endif

#include "bill.h"
#include "utils.h"

/* Client struct, note that this is an opaque type and only pointer declaration is valid.
Use the predefined functions to access members*/
typedef struct cs client;

// Returns a pointer to the memory allocated on the heap for a new client
client* clientCreate();

// Frees the memory of the passed client
int clientDestroy(client *c);

/* Checks if another instance of username exists, 
if it doesn't, it saves the username and password in 'clients.txt'*/
int clientRegister(client *c, const char *username, const char *password);

/* Looks for username matches in 'clients.txt', 
if it finds one and the password is correct it logs-in the given client*/
int clientLogin(client *c, const char *username, const char *password);

// Logout from the current client
int clientLogout(client *c);

// Adds the passed bill to the client's bill list
int clientAddBill(client *c, bill *b);

// Deletes all the bills of the logged client
void clientDeleteAll(client *c);

// Deletes the passed bill from the client's bill list
void clientDeleteBill(client *c, const char *file_name);

// Deletes the logged client
// void clientDelete(client *c);

// Prints the bills that match the flags
void clientViewAll(client *c);

// Prints the content of a bill
int clientViewBill(client *c, const char *file_name);

/* Loads dest with the passed client's username
(dest_s is the size of dest excluding the additional NULL terminating character '\0')*/
int clientGetUsername(client *c, char *dest, size_t dest_s);

/* Loads dest with the passed client's password
(dest_s is the size of dest excluding the additional NULL terminating character '\0')*/
int clientGetPassword(client *c, char *dest, size_t dest_s);

// Returns if the passed client is logged-in or not
int clientGetLoggedin(client *c);

#endif