/*============================================================================
 * Name        : client.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Fran   cesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 30/11/2021
 * Description : Header containing "Client" classes and sub classes
 *============================================================================*/

#include "client.h"

// ----- class Client ----- //
Client::Client() {
    this->username = "Default";
    this->password = "Default";
}

Client::Client(std::string username, std::string password) {
    if(username.size() < 3) throw INVALID_USERNAME;
    if(password.size() < 8) throw INVALID_PASSWORD;
    
    this->username = username;
    this->password = password;
}

Client& Client::operator=(const Client& client) {
    return *this;
}

Client::~Client() {}

// Set Client::username
void Client::setUsername(std::string username) {
    if(username.size() < 3) throw INVALID_USERNAME;

    this->username = username;
}

// Set Client::password
void Client::setPassword(std::string password) {
    if(password.size() < 8) throw INVALID_PASSWORD;

    // Hash password

    this->password = password;
}

// Get Client::username
const std::string& Client::getUsername() const {return this->username;}

// Get Client::username
const std::string& Client::getPassword() const {return this->password;}

// Checks if another istance of username exists, if it doesn't it saves the username and password in 'clients.txt'
void Client::registerClient(std::string username, std::string password) {
    std::ifstream read;
    std::ofstream write;
    std::string temp;
    std::string temp_user;

    // Checking for other istances of username
    read.open("clients.txt", std::fstream::app);

    while(std::getline(read, temp)) {
        for(int i = 0; temp[i] != ' ' && temp[i] != '\0'; i++) {
            temp_user.push_back(temp[i]);

            if(temp_user == username) {
                throw "Client '" + username + "' is already registered.\nType 'bill --login username to login.";
            }
        }
    }
    
    read.close();
    
    // Writing in the file
    write.open("clients.txt", std::fstream::app);
    write << username << " " << password << std::endl;
    write.close();
}

//
Client Client::loginClient(std::string username, std::string password) {
    std::ifstream read;
    std::string temp;
    std::string temp_user;
    Client c(username, password);

    // Checking for other istances of username
    read.open("clients.txt", std::fstream::app);

    while(std::getline(read, temp)) {
        for(int i = 0; temp[i] != ' ' && temp[i] != '\0'; i++) {
            temp_user.push_back(temp[i]);

            if(temp_user == username) {
                return c;
            }
        }
    }
    
    read.close();

    throw "Client '" + username + "' not found.\nTry 'bill --register username' to register.";
}

//
void Client::logoutClient() {
    if(username == "Default") throw "Can't logout from user '" + username + "'.";

    username = "Default";
    password = "Default";
}