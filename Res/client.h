/*============================================================================
 * Name        : client.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 09/12/2021
 * Description : Header containing "Client" classes and sub classes declarations
 *============================================================================*/

#ifndef _CLIENT_H
#define _CLIENT_H

#include <iostream>
#include <filesystem>
#include <vector>
#include <fstream>

#include "bill.h"

class Client {
    private:
    std::string username;
    std::string password;
    bool logged_in;

    // Exception strings
    const std::string INCORRECT_PASSWORD = "Incorrect password.";

    public:
    Client();
    Client& operator=(const Client& client);
    ~Client();

    // Get Client::username
    const std::string& getUsername() const;

    // Get Client::username
    const std::string& getPassword() const;

    // Returns if there is a client logged in
    bool isLoggedIn();

    /* Checks if another istance of username exists, 
    if it doesn't it saves the username and password in 'clients.txt'*/
    void registerClient(std::string username, std::string password);

    /* Looks for username matches in 'clients.txt', 
    if it finds one and the password is correct it logs-in the given client*/
    void loginClient(std::string username, std::string password);

    // Logout from the current client
    void logoutClient();

    // Adds the passed bill to the client's bill list
    void add_bill(Bill bill);

    // Deletes the passed bill from the client's bill list
    void delete_bill(std::string type, std::string due_date);

    // Deletes all the bills of the logged client
    void delete_all();

    // Prints the bills that match the flags
    void view(std::vector<std::string> flags);
};

#endif