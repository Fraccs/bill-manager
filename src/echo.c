/*============================================================================
 * Name        : echo.c
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 14/02/2022
 * Description : Source file containing echo.h functions definitons 
 *============================================================================*/

#include "echo.h"

// Enables or disables echo in stdin
void setStdinEcho(bool enable_echo) {
    #ifdef _WIN32
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE); 
    DWORD mode;

    GetConsoleMode(hStdin, &mode);

    if(!enable_echo) {
        mode &= ~ENABLE_ECHO_INPUT;
    }
    else {
        mode |= ENABLE_ECHO_INPUT;
    }

    SetConsoleMode(hStdin, mode);

    #else

    struct termios tty;

    tcgetattr(STDIN_FILENO, &tty);

    if(!enable_echo) {
        tty.c_lflag &= ~ECHO;
    }
    else {
        tty.c_lflag |= ECHO;
    }

    (void)tcsetattr(STDIN_FILENO, TCSANOW, &tty);
    
    #endif
}