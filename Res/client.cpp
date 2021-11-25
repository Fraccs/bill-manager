/*============================================================================
 * Name        : client.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 25/11/2021
 * Description : Header containing "Client" classes and sub classes
 *============================================================================*/

#include "client.h"

// ----- class Client ----- //
Client::Client() {
    this->username = "";
}

Client::Client(std::string username) {
    this->username = username;
}

// Set Client::username
void Client::setUsername(std::string username) {
    if(username.size() < 3) throw INVALID_USERNAME;

    this->username = username;
}

// Set Client::password
void Client::setPassword(std::string password) {
    if(password.size() < 8) throw INVALID_PASSWORD;

    this->password = password;
}

// Get Client::username
inline const std::string& Client::getUsername() const {return this->username;}

// Get Client::username
inline const std::string& Client::getPassword() const {return this->password;}