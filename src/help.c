/*============================================================================
 * Name        : help.c
 * Version     : v1.2.0
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : 2022 Francesco Cristiano Aliprandi
 * License     : MIT
 * Description : Source file containing help related functions definitons 
 *============================================================================*/

#include "help.h"

// Prints the help page related to the passed string
void helpPrint() {
    puts("Command type 1: bill --example");
    puts("Command type 2: bill --example argument");
    puts("Command type 3: bill --example -a argument -b argument -c argument");
    puts("For more information about commands check: https://github.com/Fraccs/bill-manager/blob/main/README.md");
}