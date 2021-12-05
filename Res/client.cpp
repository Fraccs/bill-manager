/*============================================================================
 * Name        : client.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 30/11/2021
 * Description : Source file containing client.h classes definitions
 *============================================================================*/

#include "client.h"

// ----- class Client ----- //
Client::Client() {
    this->logged_in = false;
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

// Returns if there is a client logged in
bool Client::isLoggedIn() {return this->logged_in;}

/* Checks if another istance of username exists, 
if it doesn't it saves the username and password in 'clients.txt'*/
void Client::registerClient(std::string username, std::string password) {
    std::ifstream read;
    std::ofstream write;
    std::string temp;
    std::string temp_user;

    if(username.size() < 3) throw "Username '" + username + "' is too short, minimum length is 3.";
    if(logged_in) throw "You are logged in as '" + this->username + "', log out first.";

    read.open("clients.txt", std::fstream::app);

    // Checking for other istances of username
    while(std::getline(read, temp)) {
        for(int i = 0; temp[i] != ' ' && temp[i] != '\0'; i++) {
            temp_user.push_back(temp[i]);

            if(temp_user == username) {
                throw "Client '" + username + "' is already registered.\nType 'bill --login username' to login.";
            }
        }
    }
    
    read.close(); 

    // Autologin
    this->username = username;
    this->password = password;
    this->logged_in = true;
    
    // Writing in the file
    write.open("clients.txt", std::fstream::app);
    write << username << " " << password << std::endl;
    write.close();
}

/* Looks for username matches in 'clients.txt', 
if it finds one and the password is correct it logs-in the given client*/
void Client::loginClient(std::string username, std::string password) {
    std::ifstream read;
    std::string temp;
    std::string temp_user, temp_pass;

    if(username.size() < 3) throw "Username '" + username + "' is too short, minimum length is 3.";
    if(logged_in) throw "You are logged in as '" + username + "', log out first.";

    // Checking for other istances of username
    read.open("clients.txt", std::fstream::app);

    while(std::getline(read, temp)) {
        temp_user = "";
        temp_pass = "";

        for(int i = 0; temp[i] != ' ' && temp[i] != '\0'; i++) {
            temp_user.push_back(temp[i]);
        }

        for(int i = temp_user.size() + 1; temp[i] != ' ' && temp[i] != '\0'; i++) {
            temp_pass.push_back(temp[i]);
        }

        if(temp_user == username) {
            if(temp_pass == password) {
                this->username = username;
                this->password = password;
                this->logged_in = true;
                return;
            }
            else {
                throw INCORRECT_PASSWORD;
            }
        }
    }
    
    read.close();

    // Client not found
    throw "Client '" + username + "' not found.\nTry 'bill --register username' to register.";
}

//  Logout from the current client
void Client::logoutClient() {
    if(username == "Default") throw "Can't logout from user '" + username + "'.";

    this->username = "Default";
    this->password = "Default";
    this->logged_in = false;
}