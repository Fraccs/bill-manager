/*============================================================================
 * Name        : main.cpp
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 29/11/2021
 * Description : Main 
 *============================================================================*/

#include <iostream>
#include <vector>

#include "Res/client.h"
#include "Res/logs.h"
#include "Res/command_interpreter.h"

int main() {
    Client client;
    std::string command;
    std::string argument;
    std::vector<std::string> flags;

    while(true) {
        std::cout << ">: ";
        std::cin >> command;

        if(command == "bill -q" || command == "bill --quit") return 0;

        flags = find_flags(command);

        // Iterating through the flags
        for(int i = 0; i < flags.size(); i++) {
            if(flags[i] == "-a" || flags[i] == "--add") {
                argument = get_argument(command, flags[i]);  
            }

            if(flags[i] == "-r" || flags[i] == "--register") {
                argument = get_argument(command, flags[i]);
            
                // Get the password (no echo)
            }

            if(flags[i] == "--login") {
                argument = get_argument(command, flags[i]);
            
                // Get the password (no echo)
            }

            if(flags[i] == "--logout") {
                std::cout << "Logged out from user '" << client.getUsername() << "' successfully." << std::endl;
            }
        }
    }

    return 0;
}