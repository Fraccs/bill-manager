/*============================================================================
 * Name        : main.cpp
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 30/11/2021
 * Description : Main 
 *============================================================================*/

#include <iostream>
#include <vector>

#include "Res/client.h"
#include "Res/logs.h"
#include "Res/command_interpreter.h"
#include "Res/help.h"

int main() {
    Client client;
    std::string command;
    std::string argument;
    std::string temp;
    std::vector<std::string> flags;

    while(true) {
        std::cout << ">: ";
        fflush(stdin);
        std::getline(std::cin, command);

        // Blank input
        if(command == "") continue;

        if(!starts_with_bill(command)) {
            std::cout << "Unknown command '" << command << "'." << std::endl;
            std::cout << "Try 'bill --help' for more info." << std::endl;   
            continue;
        }

        // Getting all the flags in command
        flags = find_flags(command);

        if(flags.size() == 0) {
            std::cout << "No flags found in '" + command + "'." << std::endl;
            continue;
        }

        for(int i = 0; i < flags.size(); i++) {
            if(flags[i] == "--client") {
                std::cout << client.getUsername() << std::endl;                
            }

            if(flags[i] == "--help") {
                argument = get_argument(command, flags[i]);

                print_help(argument);
            }

            if(flags[i] == "--login") {
                argument = get_argument(command, flags[i]);

                std::cout << "Password for '" << argument << "': ";
                std::cin >> temp;

                try {
                    client.loginClient(argument, temp);
                }
                catch(const std::string err) {
                    std::cout << err << std::endl;
                }
            }

            if(flags[i] == "--logout") {
                try {
                    client.logoutClient();
                }
                catch(const std::string err) {
                    std::cout << err << std::endl;
                }
            }

            if(flags[i] == "--quit") {
                return 0;
            }

            if(flags[i] == "-r" || flags[i] == "--register") {
                argument = get_argument(command, flags[i]);

                std::cout << "Password: ";
                std::cin >> temp;

                try {
                    client.registerClient(argument, temp);
                }
                catch(const std::string err) {
                    std::cout << err << std::endl;
                }
            }
        }
    }
}