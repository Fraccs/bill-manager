/*============================================================================
 * Name        : echo.c
 * Version     : v1.0.0
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 17/04/2022
 * Description : Source file containing stdin-echo related functions definitions 
 *============================================================================*/

#include "echo.h"

// Enables or disables echo in stdin
void echoEnable(bool enable_echo) {
    struct termios tty;

    tcgetattr(STDIN_FILENO, &tty);

    if(!enable_echo) {
        tty.c_lflag &= ~ECHO;
    }
    else {
        tty.c_lflag |= ECHO;
    }

    (void)tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}