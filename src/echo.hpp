/*============================================================================
 * Name        : echo.hpp
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 13/02/2022
 * Description : Header file containing stdin-echo related function declarations
 *============================================================================*/

#ifndef _ECHO_HPP
#define _ECHO_HPP

#ifdef _WIN32
#include <windows.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

// Enables or disables echo in stdin
void setStdinEcho(bool);

#endif