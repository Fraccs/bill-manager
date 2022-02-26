/*============================================================================
 * Name        : utils.c
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 26/02/2022
 * Description : Source file containing multi-puropose functions declarations
 *============================================================================*/

#include "utils.h"

// Converts a char into a C string
char *charToString(char c) {
    char *str = malloc(sizeof(char) * 2);
    
    str[0] = c;
    str[1] = '\0';

    return str;
}