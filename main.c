/*============================================================================
 * Name        : main.c
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 28/02/2022
 * Description : Main 
 *============================================================================*/

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/stat.h>
#endif

#include "src/client.h"
#include "src/bill.h"
#include "src/cli.h"
#include "src/echo.h"
#include "src/help.h"
#include "src/logs.h"
#include "src/utils.h"

#define COMM_MAXLEN 80
#define MNFG_MAXLEN 20
#define ARGM_MAXLEN 30

int main() {
    client *c = clientCreate();
    bill *b = billCreate();
    char temp_user[USER_MAXLEN + 1];
    char temp_pass[PASS_MAXLEN + 1];
    char command[COMM_MAXLEN + 1];
    char main_flag[MNFG_MAXLEN + 1];
    char argument[ARGM_MAXLEN + 1];
    char sub_flags[10][3];
    int flags_s = 0;
    int ret; // Error checking

    #ifndef _WIN32
    mkdir("data", S_IRWXU);
    #else
    CreateDirectory("data", NULL);
    #endif

    if(c == NULL || b == NULL) {
        return EXIT_FAILURE;
    }

    while(true) {
        printf(">: ");
        fflush(stdin);
        fgets(command, COMM_MAXLEN, stdin);
        strtok(command, "\n");

        if(!cliStartsWithBill(command)) {
            printf("Unknown command '%s'.\n", command);
            printf("Try 'bill --help' for more info.\n");   
            continue;
        }

        // Getting the main flag ('--example')
        cliGetMainFlag(main_flag, command, MNFG_MAXLEN);

        if(strlen(main_flag) == 0) {
            printf("No main flag found in '%s'.\n", command);
            continue;
        }
        
        if(strcmp(main_flag, "--add") == 0) {
            if(!clientGetLoggedin(c)) {
                printf("Log in a client first!\n");
                continue;
            }

            flags_s = cliGetSubFlags(sub_flags, command);

            for(int i = 0; i < flags_s; i++) {
                if(strcmp(sub_flags[i], "-c") == 0) {
                    cliGetArgument(argument, command, "-c", COMM_MAXLEN);
                    billSetCost(b, atof(argument));
                }

                if(strcmp(sub_flags[i], "-e") == 0) {
                    cliGetArgument(argument, command, "-e", COMM_MAXLEN);
                    billSetDate(b, argument, "d");
                }

                if(strcmp(sub_flags[i], "-d") == 0) {
                    cliGetArgument(argument, command, "-d", COMM_MAXLEN);
                    billSetDate(b, argument, "p");
                }

                if(strcmp(sub_flags[i], "-p") == 0) {
                    billSetPaid(b, true);
                }   

                if(strcmp(sub_flags[i], "-t") == 0) {
                    cliGetArgument(argument, command, "-t", COMM_MAXLEN);
                    billSetType(b, argument);
                }    
            }
            
            clientAddBill(c, b);     
        }

        if(strcmp(main_flag, "--clear") == 0) {
            utilsClearConsole();
        }

        if(strcmp(main_flag, "--client") == 0) {
            printf("%s\n", clientGetUsername(c));                
        }

        if(strcmp(main_flag, "--delete") == 0) {
            if(!clientGetLoggedin(c)) {
                printf("Log in a client first!\n");
                continue;
            }

            flags_s = cliGetSubFlags(sub_flags, command);

            if(strcmp(sub_flags[0], "-a") == 0) {
                clientDeleteAll(c);
                continue;
            }
            
            if(strcmp(sub_flags[0], "-n") == 0) {
                cliGetArgument(argument , command, sub_flags[0], ARGM_MAXLEN);
                clientDeleteBill(c, argument);
            }

            if(strcmp(sub_flags[0], "-c") == 0) {
                // deleteClient(c);
            }
        }

        if(strcmp(main_flag, "--help") == 0) {
            helpPrint();
        }

        if(strcmp(main_flag, "--login") == 0) {
            cliGetArgument(argument, command, main_flag, ARGM_MAXLEN);

            printf("Password for '%s': ", argument);

            echoEnable(false);
            fgets(temp_pass, PASS_MAXLEN, stdin);
            echoEnable(true);

            printf("\n");

            clientLogin(c, argument, temp_pass);
        }

        if(strcmp(main_flag, "--logout") == 0) {
            if(clientLogout(c) == -1) {
                printf("An error occurred during the logout process.\n");
            }
        }

        if(strcmp(main_flag, "--quit") == 0) {
            clientDestroy(c);
            billDestroy(b);
            return EXIT_SUCCESS;
        }

        if(strcmp(main_flag, "--register") == 0) {
            ret = cliGetArgument(temp_user, command, main_flag, USER_MAXLEN);

            if(ret == -1) {
                printf("No argument provided for '%s'.\n", command);
            } 

            printf("Password: ");

            echoEnable(false);
            fgets(temp_pass, PASS_MAXLEN, stdin);
            strtok(temp_pass, "\n");
            echoEnable(true);

            printf("\n");

            ret = clientRegister(c, temp_user, temp_pass);

            if(ret == -1) {
                printf("An error occurred in the registration process.\n");
            }
        }

        if(strcmp(main_flag, "--view") == 0) {
            if(!clientGetLoggedin(c)) {
                printf("Log in a client first!\n");
                continue;
            }
 
            flags_s = cliGetSubFlags(sub_flags, command);

            if(flags_s == 0) {
                clientViewAll(c);
            }
            else {
                for(int i = 0; i < flags_s; i++) {
                    if(strcmp(sub_flags[i], "-n") == 0) {
                        cliGetArgument(argument, command, sub_flags[i], ARGM_MAXLEN);
                        clientViewBill(c, argument);
                    }
                }
            }
        }
    }
}