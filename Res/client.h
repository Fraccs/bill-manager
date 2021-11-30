/*============================================================================
 * Name        : client.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 30/11/2021
 * Description : Header containing "Client" classes and sub classes prototypes
 *============================================================================*/

#ifndef _CLIENT_H
#define _CLIENT_H

#include <iostream>
#include <vector>
#include <fstream>

#include "bill.h"

class Client {
    private:
    std::string username;
    std::string password;
    std::vector<Bill> bill_list;
    bool logged_in;

    // Exception strings
    const std::string INVALID_USERNAME = "Exception handled: invalid username.";
    const std::string INVALID_PASSWORD = "Exception handled: invalid password.";

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

    // Checks if another istance of username exists, if it doesn't it saves the username and password in 'clients.txt'
    void registerClient(std::string username, std::string password);

    //
    void loginClient(std::string username, std::string password);

    //
    void logoutClient();
};

#endif