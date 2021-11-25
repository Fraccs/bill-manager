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

#include "Res/client.h"
#include "Res/logs.h"

// Prototypes
int print_menu();

int main() {
    Client client;
    std::string temp_string;
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
                std::cout << "REGISTER"              << std::endl; 
                std::cout << "---------------------" << std::endl;
                std::cout << "Username: "            << std::endl;
                std::cin >> temp_string;
                client.setUsername(temp_string);
                std::cout << "Password: "            << std::endl;
                std::cin >> temp_string;
                client.setPassword(temp_string);
            }
            break;

            case 2: {
                
            }
            break;

            case 3: {
                
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
    std::cout << "0. Quit"               << std::endl;
    std::cout << "1. Register"           << std::endl;
    std::cout << "2. Login"              << std::endl;
    std::cout << "3. Logout"             << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << "Choice: "              << std::endl;
    std::cin >> choice;

    return choice;
}