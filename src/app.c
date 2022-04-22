/*============================================================================
 * Name        : app.c
 * Version     : v1.0.0
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 22/04/2022
 * Description : Source file containing the app's core functions definitions
 *============================================================================*/

#include "app.h"

// Buffering setup
void initApplication() {
    setvbuf(stdin, NULL, _IOLBF, 0);
    setvbuf(stdout, NULL, _IOLBF, 0);
    setvbuf(stderr, NULL, _IOLBF, 0);
}

// Program's core function
int startApplication(int argc, char *argv[]) {
    /* ---- I/O ---- */
    bill *b = billCreate();
    struct stat st = {0};
    int ret; // Error checking

    /* ---- CLI ---- */
    char command[COMM_MAXLEN + 1];
    char main_flag[MNFG_MAXLEN + 1];
    char **sub_flags;
    char argument[ARGM_MAXLEN + 1];
    size_t flags_s = 0;

    // Failed bill allocation
    if(b == NULL) return EXIT_FAILURE;

    // /var/lib/billman was removed
    if(stat("/var/lib/billman", &st) == -1) {
        ret = mkdir("/var/lib/billman", 07777); // ALLPERMS

        if(ret == -1) {
            perror("Could not create '/var/lib/billman'");
        }
        else {
            fprintf(stderr, "Re-created '/var/lib/billman' directory\n");
            return EXIT_SUCCESS;
        }

        fprintf(stderr, "Please run the program with root privileges\n");
                
        return EXIT_FAILURE;
    }

    if(argc < 2) { // No args provided
        helpPrint();
        return EXIT_SUCCESS;
    }

    /* ---- Command parsing and execution ---- */
    cliExtractCommand(command, argc, argv);
    cliGetMainFlag(main_flag, command, MNFG_MAXLEN);

    if(strnlen(main_flag, MNFG_MAXLEN) == 0) {
        printf("No main flag found in '%s'.\n", command);
        return EXIT_FAILURE;
    }

    /* ---- Command: 'add' ---- */
    if(strncmp(main_flag, "--add", MNFG_MAXLEN) == 0) {
        flags_s = cliGetSubFlags(&sub_flags, command);

        for(int i = 0; i < flags_s; i++) {
            if(strncmp(sub_flags[i], "-c", SUBFLAG_LEN) == 0) {
                cliGetArgument(argument, command, "-c", ARGM_MAXLEN);
                billSetCost(b, atof(argument));
            }

            if(strncmp(sub_flags[i], "-e", SUBFLAG_LEN) == 0) {
                cliGetArgument(argument, command, "-e", ARGM_MAXLEN);
                billSetDate(b, argument, "d");
            }

            if(strncmp(sub_flags[i], "-d", SUBFLAG_LEN) == 0) {
                cliGetArgument(argument, command, "-d", ARGM_MAXLEN);
                billSetDate(b, argument, "p");
            }

            if(strncmp(sub_flags[i], "-p", SUBFLAG_LEN) == 0) {
                billSetPaid(b, true);
            }   

            if(strncmp(sub_flags[i], "-t", SUBFLAG_LEN) == 0) {
                cliGetArgument(argument, command, "-t", ARGM_MAXLEN);
                billSetType(b, argument);
            }    
        }
        
        billAdd(b);     

        return EXIT_SUCCESS;
    }

    /* ---- Command: 'delete' ---- */
    if(strncmp(main_flag, "--delete", MNFG_MAXLEN) == 0) {
        flags_s = cliGetSubFlags(&sub_flags, command);

        if(strcmp(sub_flags[0], "-n") == 0) {
            cliGetArgument(argument, command, sub_flags[0], ARGM_MAXLEN);
            billDelete(argument);

            return EXIT_SUCCESS;
        }
    }

    /* ---- Command: 'help' ---- */
    if(strncmp(main_flag, "--help", MNFG_MAXLEN) == 0) {
        helpPrint();

        return EXIT_SUCCESS;
    }

    /* ---- Command: 'view' ---- */
    if(strncmp(main_flag, "--view", MNFG_MAXLEN) == 0) {
        flags_s = cliGetSubFlags(&sub_flags, command);

        if(strcmp(sub_flags[0], "-n") == 0) {
            cliGetArgument(argument, command, sub_flags[0], ARGM_MAXLEN);
            ret = billView(argument);
        
            if(ret == -1) {
                printf("An error occurred during the view process.\n");
    
                return EXIT_FAILURE;
            }
        }

        if(strcmp(sub_flags[0], "-a") == 0) {
            ret = billViewAll();
        
            if(ret == -1) {
                printf("An error occurred during the view process.\n");
    
                return EXIT_FAILURE;
            }
        }
    }
}