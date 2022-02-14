/*============================================================================
 * Name        : client.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 12/02/2022
 * Description : Header containing "Client" classes and sub classes declarations
 *============================================================================*/

#ifndef _CLIENT_HPP
#define _CLIENT_HPP

#include <iostream>
#include <filesystem>
#include <vector>
#include <fstream>

#include "bill.hpp"

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
    void addBill(Bill bill);

    // Deletes all the bills of the logged client
    void deleteAll();

    // Deletes the passed bill from the client's bill list
    void deleteBill(std::string file_name);

    // Deletes the logged client
    void deleteClient();

    // Prints the bills that match the flags
    void viewAll();

    // Prints the content of a bill
    void viewBill(std::string file_name);
};

#endif