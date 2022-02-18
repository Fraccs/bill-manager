/*============================================================================
 * Name        : utils.c
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 18/02/2022
 * Description : Source file containing multi-puropose functions declarations
 *============================================================================*/

#include "utils.h"

// Converts a char to a C string
void charToString(char* dest, char c) {
    dest[0] = c;
    dest[1] = '\0';
}