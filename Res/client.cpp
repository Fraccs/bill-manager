/*============================================================================
 * Name        : client.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
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

Client& Client::operator=(const Client& client) {
    return *this;
}

Client::~Client() {}

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

    read.open("clients.txt", std::fstream::app);

    // Checking for other istances of username
    while(std::getline(read, temp)) {
        for(int i = 0; temp[i] != ' ' && temp[i] != '\0'; i++) {
            temp_user.push_back(temp[i]);

            if(temp_user == username) {
                throw "Client '" + username + "' is already registered.\nType 'bill --login username to login.";
            }
        }
    }
    
    read.close(); 

    // Autologin
    this->username = username;
    this->password = password;
    
    // Writing in the file
    write.open("clients.txt", std::fstream::app);
    write << username << " " << password << std::endl;
    write.close();
}

//
void Client::loginClient(std::string username, std::string password) {
    std::ifstream read;
    std::string temp;
    std::string temp_user, temp_pass;

    // Checking for other istances of username
    read.open("clients.txt", std::fstream::app);

    while(std::getline(read, temp)) {
        for(int i = 0; temp[i] != ' ' && temp[i] != '\0'; i++) {
            temp_user.push_back(temp[i]);
        }

        for(int i = temp_user.size() + 1; temp[i] != ' ' && temp[i] != '\0'; i++) {
            temp_pass.push_back(temp[i]);
        }

        if(temp_user == username && temp_pass == password) {
            this->username = username;
            this->password = password;
            return;
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