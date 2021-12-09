/*============================================================================
 * Name        : client.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 09/12/2021
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

    read.open("Data/clients.txt", std::fstream::app);

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
    write.open("Data/clients.txt", std::fstream::app);
    write << username << " " << password << std::endl;
    write.close();

    // Creating a directory for 'username'
    std::filesystem::create_directory("Data/" + username);
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
    read.open("Data/clients.txt", std::fstream::app);

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

// Adds the passed bill to the client's bill list
void Client::add_bill(Bill bill) {
    std::ofstream write;
    int num = 0;

    auto file_iterator = std::filesystem::directory_iterator("Data/" + username + "/");

    // Getting the number of files in the client's directory
    for(auto& file: file_iterator) {
        if(file.is_regular_file()){
            num++;
        }
    }

    write.open("Data/" + username + "/bill" + std::to_string(num + 1) + ".txt", std::fstream::app);
    
    write << "Type: " << bill.getType() << std::endl;
    write << "Cost: " << bill.getCost() << std::endl;
    write << "Usage: " << bill.getUsage() << std::endl;

    if(bill.getPaid()) {
        write << "Paid: True" << std::endl;
    }
    else {
        write << "Paid: False" << std::endl;
    }

    write << "Paid in: " << bill.getPaidDate() << std::endl;
    write << "Due date: " << bill.getDueDate() << std::endl;
   
    write.close();
}

// Deletes the passed bill from the client's bill list
void Client::delete_bill(std::string file_name) {
    std::string temp;
    std::string path_string;
    std::filesystem::path path;

    auto file_iterator = std::filesystem::directory_iterator("Data/" + username + "/");

    // Iterating through all the lines of all the files
    for(auto& file: file_iterator) {
        if(file.is_regular_file()){
            // Getting file path (Data/User/bill.txt)
            path = file;
            // Path to std::string
            path_string = path.u8string();

            if(path_string == "Data/" + username + "/" + file_name + ".txt") {
                std::remove(path_string.c_str());
            }
        }
    }
}

// Deletes the passed bill from the client's bill list
void Client::delete_all() {
    auto file_iterator = std::filesystem::directory_iterator("Data/" + username + "/");
    std::string path_string;
    std::filesystem::path path;

    // Iterating through all the lines of all the files
    for(auto& file: file_iterator) {
        if(file.is_regular_file()){
            // Getting file path
            path = file;
            // Path to std::string
            path_string = path.u8string();

            std::remove(path_string.c_str());            
       }
    }
}

// Prints the bills that match the flags
void Client::view(std::vector<std::string> flags) {
    std::ifstream read;
    std::string temp;
    std::string path_string;
    std::filesystem::path path;

    auto file_iterator = std::filesystem::directory_iterator("Data/" + username + "/");

    // Iterating through the directory
    for(auto& file: file_iterator) {
        if(file.is_regular_file()){
            // Getting file path
            path = file;
            // Path to std::string
            path_string = path.u8string();

            read.open(path_string);

            while(std::getline(read, temp)) {
                   
            }

            read.close();
        }
    }   
}