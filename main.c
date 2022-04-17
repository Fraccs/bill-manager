/*============================================================================
 * Name        : main.c
 * Version     : v0.0.1
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 17/04/2022
 * Description : Main 
 *============================================================================*/

/* ---- Headers ---- */
#include "src/app.h"

int main(int argc, char *argv[]) {
    int err = initApplication(argc, argv);

    return err;
}