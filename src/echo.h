/*============================================================================
 * Name        : echo.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 14/02/2022
 * Description : Header file containing stdin-echo related functions declarations
 *============================================================================*/

#ifndef _ECHO_H
#define _ECHO_H

#include <stdbool.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

// Enables or disables echo in stdin
void setStdinEcho(bool);

#endif