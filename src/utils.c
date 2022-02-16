/*============================================================================
 * Name        : utils.c
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 16/02/2022
 * Description : Source file containing multi-puropose functions declarations
 *============================================================================*/

#include "utils.h"

// Converts a char to a char*
char* charToString(char c) {
    char* s = malloc(sizeof(char) * 2);

    s[0] = c;
    s[1] = '\0';

    return s;
}