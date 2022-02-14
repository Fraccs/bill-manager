/*============================================================================
 * Name        : main.c
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 14/02/2022
 * Description : Main 
 *============================================================================*/

#include <stdio.h>

#include "src/client.h"
#include "src/bill.h"
#include "src/logs.h"
#include "src/command_interpreter.h"
#include "src/help.h"

int main() {
    char *command;
    char *main_argument;
    char *temp;
    char *main_flag;
    char **flags;
    char **args;

    // Directory where all the data will be stored
    // filesystem::create_directory("Data");

    while(true) {
        printf(">: ");
        fflush(stdin);
        getline(cin, command);

        // Blank input
        if(command == "") continue;

        if(!starts_with_bill(command)) {
            printf("Unknown command '%s'.\n", command);
            printf("Try 'bill --help' for more info.\n");   
            continue;
        }

        // Getting the main flag ('--example')
        main_flag = find_main_flag(command);

        if(main_flag.size() == 0) {
            printf("No main flag found in '%s'.\n", command);
            continue;
        }

        if(main_flag == "--add") {
            if(!client.isLoggedIn()) {
                cout << "Log in a client first!" << endl;
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
            catch(const string err) {
                cout << err << endl;
                continue;
            }
                   
            client.addBill(temp_bill);     
        }

        if(main_flag == "--client") {
            cout << client.getUsername() << endl;                
        }

        if(main_flag == "--delete") {
            if(!client.isLoggedIn()) {
                cout << "Log in a client first!" << endl;
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

            cout << "Password for '" << main_argument << "': ";
            cin >> temp;

            try {
                client.loginClient(main_argument, temp);
            }
            catch(const string err) {
                cout << err << endl;
            }
        }

        if(main_flag == "--logout") {
            try {
                client.logoutClient();
            }
            catch(const string err) {
                cout << err << endl;
            }
        }

        if(main_flag == "--quit") {
            return 0;
        }

        if(main_flag == "--register") {
            main_argument = get_argument(command, main_flag);

            cout << "Password: ";
            cin >> temp;

            try {
                client.registerClient(main_argument, temp);
            }
            catch(const string err) {
                cout << err << endl;
            }
        }

        if(main_flag == "--view") {
            if(!client.isLoggedIn()) {
                cout << "Log in a client first!" << endl;
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
                        catch(const string err) {
                            cout << err << endl;
                        }
                    }
                }
            }
        }
    }
}