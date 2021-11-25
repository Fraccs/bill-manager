/*============================================================================
 * Name        : main.cpp
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 25/11/2021
 * Description : Main 
 *============================================================================*/

#include <iostream>

#include "Res/client.h"
#include "Res/logs.h"

// Prototypes
int print_menu();

int main() {
    Client client;
    std::string username;
    std::string password;
    bool done = false;
    int choice;

    while(!done) {
        choice = print_menu(); 

        switch(choice) {
            case 0: {
                // Credits
                return 0;
            }
            break;

            case 1: {
                /*
                while(true) {
                    std::cout << "REGISTER"              << std::endl; 
                    std::cout << "---------------------" << std::endl;
                    std::cout << "Username: "            << std::endl;
                    std::cin >> username;
                    std::cout << "Password: "            << std::endl;
                    std::cin >> password;
 
                    try {
                        client.setUsername(username);
                        client.setPassword(password);
                        break;
                    }
                    catch(const std::string err) {
                        logToTxt("logs.txt", err);
                        // Print error to the user
                        continue;
                    }
                }
                */
            }
            break;

            case 2: {
                /*
                std::cout << "LOGIN"                 << std::endl; 
                std::cout << "---------------------" << std::endl;
                std::cout << "Username: "            << std::endl;
                // Check for matching usernames
                std::cout << "Password: "            << std::endl;
                // Check for matching passwords
                */
            }
            break;

            case 3: {
                // Code for logout
            }
            break;

            default: {

            }
            break;
        }
    }

    return 0;
}


// Prints the main menu and returns the choice
int print_menu() {
    int choice;

    std::cout << "MENU'"                 << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << "0.  Quit"              << std::endl;
    std::cout << "1.  Register"          << std::endl;
    std::cout << "2.  Login"             << std::endl;
    std::cout << "3.  Logout"            << std::endl;
    std::cout << "4.  Insert bill"       << std::endl;
    std::cout << "5.  Remove bill"       << std::endl;
    std::cout << "6.  Get all bills"     << std::endl;
    std::cout << "7.  Get bill by date"  << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << "Choice: "              << std::endl;
    std::cin >> choice;

    return choice;
}