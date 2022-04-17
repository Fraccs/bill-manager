/*============================================================================
 * Name        : echo.h
 * Version     : v1.0.0
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 17/04/2022
 * Description : Header file containing stdin-echo related functions declarations
 *============================================================================*/

#ifndef _ECHO_H
#define _ECHO_H

/* ---- Headers ---- */
#include <stdbool.h>

#include <termios.h>
#include <unistd.h>

// Enables or disables echo in stdin
void echoEnable(bool enable_echo);

#endif