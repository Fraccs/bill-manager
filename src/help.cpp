/*============================================================================
 * Name        : help.cpp
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 12/02/2022
 * Description : Source file containing help.h functions definitons 
 *============================================================================*/

#include "help.hpp"

// Prints the help page related to the passed string
void print_help() {
    std::cout << "Command type 1: bill --example" << std::endl;
    std::cout << "Command type 2: bill --example argument" << std::endl;
    std::cout << "Command type 3: bill --example -a argument -b argument -c argument" << std::endl;
    std::cout << "For more information about commands check: https://github.com/Fraccs/bill-manager/blob/main/README.md" << std::endl;
}