/*============================================================================
 * Name        : v1.0.0
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 18/04/2022
 * Description : Source file containing the app's core functions definitions
 *============================================================================*/

#include "app.h"

// Main function
int startApplication(int argc, char *argv[]) {
    bill *b = billCreate();
    char command[COMM_MAXLEN + 1];
    char main_flag[MNFG_MAXLEN + 1];
    char argument[ARGM_MAXLEN + 1];
    char sub_flags[10][3];
    int flags_s = 0;
    int ret; // Error checking

    // Failed allocation
    if(b == NULL) { 
        return EXIT_FAILURE;
    }

    // No commands provided
    if(argc < 2) {
        helpPrint();
        return EXIT_FAILURE;
    }

    // Data directory
    mkdir("data", S_IRWXU);

    /* ---- Command parsing and analysis ---- */
    cliExtractCommand(command, argc, argv);
    cliGetMainFlag(main_flag, command, MNFG_MAXLEN);

    if(strlen(main_flag) == 0) {
        printf("No main flag found in '%s'.\n", command);
    }

    if(strncmp(main_flag, "--add", MNFG_MAXLEN) == 0) {
        flags_s = cliGetSubFlags(sub_flags, command);

        for(int i = 0; i < flags_s; i++) {
            // TODO: sub_flags need fix
            // if(strcmp(sub_flags[i], "-c") == 0) {
            //     cliGetArgument(argument, command, "-c", COMM_MAXLEN);
            //     billSetCost(b, atof(argument));
            // }

            // if(strcmp(sub_flags[i], "-e") == 0) {
            //     cliGetArgument(argument, command, "-e", COMM_MAXLEN);
            //     billSetDate(b, argument, "d");
            // }

            // if(strcmp(sub_flags[i], "-d") == 0) {
            //     cliGetArgument(argument, command, "-d", COMM_MAXLEN);
            //     billSetDate(b, argument, "p");
            // }

            // if(strcmp(sub_flags[i], "-p") == 0) {
            //     billSetPaid(b, true);
            // }   

            // if(strcmp(sub_flags[i], "-t") == 0) {
            //     cliGetArgument(argument, command, "-t", COMM_MAXLEN);
            //     billSetType(b, argument);
            // }    
        }
        
        billAdd(b);     
    }

    if(strcmp(main_flag, "--clear") == 0) {
        utilsClearConsole();
    }

    if(strcmp(main_flag, "--delete") == 0) {
        flags_s = cliGetSubFlags(sub_flags, command);
        
        if(strcmp(sub_flags[0], "-n") == 0) {
            cliGetArgument(argument, command, sub_flags[0], ARGM_MAXLEN);
            billDelete(argument);
        }
    }

    if(strcmp(main_flag, "--help") == 0) {
        helpPrint();
    }

    if(strcmp(main_flag, "--quit") == 0) {
        billDestroy(b);
        return EXIT_SUCCESS;
    }

    if(strcmp(main_flag, "--view") == 0) {
        flags_s = cliGetSubFlags(sub_flags, command);

        for(int i = 0; i < flags_s; i++) {
            if(strcmp(sub_flags[i], "-n") == 0) {
                cliGetArgument(argument, command, sub_flags[i], ARGM_MAXLEN);
                ret = billView(argument);
            
                if(ret == -1) {
                    printf("An error occurred during the view process.\n");
                }
            }
        }
    }
}