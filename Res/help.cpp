/*============================================================================
 * Name        : help.cpp
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 30/11/2021
 * Description : Header containing help functions bodies 
 *============================================================================*/

#include "help.h"

// Prints the help page related to the passed string
void print_help(std::string arg) {
    if(arg.empty()) {
        std::cout << "base" << std::endl;
    }

    if(arg == "client") {
        std::cout << "client" << std::endl;
    }

    if(arg == "bill") {
        std::cout << "bill" << std::endl;
    }
}