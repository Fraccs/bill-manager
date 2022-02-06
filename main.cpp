/*============================================================================
 * Name        : main.cpp
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 06/02/2022
 * Description : Main 
 *============================================================================*/

#include <iostream>
#include <filesystem>
#include <vector>

#include "src/client.h"
#include "src/bill.h"
#include "src/logs.h"
#include "src/command_interpreter.h"
#include "src/help.h"

int main() {
    Client client;
    Bill temp_bill;
    std::string command;
    std::string main_argument;
    std::string temp;
    std::string main_flag;
    std::vector<std::string> flags;
    std::vector<std::string> args;

    // Directory where all the data will be stored
    std::filesystem::create_directory("Data");

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

        // Getting the main flag ('--example')
        main_flag = find_main_flag(command);

        if(main_flag.size() == 0) {
            std::cout << "No main flag found in '" + command + "'." << std::endl;
            continue;
        }

        if(main_flag == "--add") {
            if(!client.isLoggedIn()) {
                std::cout << "Log in a client first!" << std::endl;
                continue;
            }

            flags = find_flags(command);

            try {
                for(int i = 0; i < flags.size(); i++) {
                    if(flags[i] == "-c") {
                        temp_bill.setCost(stof(get_argument(command, flags[i])));
                    }

                    if(flags[i] == "-d") {
                        temp_bill.setPaidDate(get_argument(command, flags[i]));
                    }

                    if(flags[i] == "-e") {
                        temp_bill.setDueDate(get_argument(command, flags[i]));
                    }

                    if(flags[i] == "-u") {     
                        temp_bill.setUsage(stof(get_argument(command, flags[i])));             
                    }

                    if(flags[i] == "-p") {
                        temp_bill.setPaid();
                    }   

                    if(flags[i] == "-t") {
                        temp_bill.setType(get_argument(command, flags[i]));
                    }    
                }
            }
            catch(const std::string err) {
                std::cout << err << std::endl;
                continue;
            }
                   
            client.addBill(temp_bill);     
        }

        if(main_flag == "--client") {
            std::cout << client.getUsername() << std::endl;                
        }

        if(main_flag == "--delete") {
            if(!client.isLoggedIn()) {
                std::cout << "Log in a client first!" << std::endl;
                continue;
            }

            flags = find_flags(command);

            // bill --delete -a (deletes all bills)
            if(flags[0] == "-a") {
                client.deleteAll();
                continue;
            }
            
            if(flags[0] == "-n") {
                client.deleteBill(get_argument(command, flags[0]));
            }

            if(flags[0] == "-c") {
                client.deleteClient();
            }
        }

        if(main_flag == "--help") {
            print_help();
        }

        if(main_flag == "--login") {
            main_argument = get_argument(command, main_flag);

            std::cout << "Password for '" << main_argument << "': ";
            std::cin >> temp;

            try {
                client.loginClient(main_argument, temp);
            }
            catch(const std::string err) {
                std::cout << err << std::endl;
            }
        }

        if(main_flag == "--logout") {
            try {
                client.logoutClient();
            }
            catch(const std::string err) {
                std::cout << err << std::endl;
            }
        }

        if(main_flag == "--quit") {
            return 0;
        }

        if(main_flag == "--register") {
            main_argument = get_argument(command, main_flag);

            std::cout << "Password: ";
            std::cin >> temp;

            try {
                client.registerClient(main_argument, temp);
            }
            catch(const std::string err) {
                std::cout << err << std::endl;
            }
        }

        if(main_flag == "--view") {
            if(!client.isLoggedIn()) {
                std::cout << "Log in a client first!" << std::endl;
                continue;
            }

            flags = find_flags(command);

            if(flags[0] == "NOFLAGS") {
                client.viewAll();
            }
            else {
                for(int i = 0; i < flags.size(); i++) {
                    if(flags[i] == "-n") {
                        try {
                            client.viewBill(get_argument(command, flags[i]));
                        }
                        catch(const std::string err) {
                            std::cout << err << std::endl;
                        }
                    }
                }
            }
        }
    }
}