/*============================================================================
 * Name        : main.cpp
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 21/11/2021
 * Description : Main 
 *============================================================================*/

#include "client.h"
#include "logs.h"

int main() {
    Bill a;

    try {
        a.setCost(-1);
    }
    catch(const std::string str) {
        logToTxt("logs.txt", str);
    }
    
    return 0;
}