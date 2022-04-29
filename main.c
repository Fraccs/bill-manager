/*============================================================================
 * Name        : main.c
 * Version     : v1.0.0
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 19/04/2022
 * Description : Main 
 *============================================================================*/

/* ---- Headers ---- */
#include "src/app.h"

int main(int argc, char *argv[]) {
    initApplication();
    
    int err = startApplication(argc, argv);

    return err;
}