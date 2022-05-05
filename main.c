/*============================================================================
 * Name        : main.c
 * Version     : v1.2.0
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : 2022 Francesco Cristiano Aliprandi
 * License     : MIT
 * Description : Main 
 *============================================================================*/

/* ---- Headers ---- */
#include "src/app.h"

int main(int argc, char *argv[]) {
    initApplication();
    
    int err = startApplication(argc, argv);

    return err;
}