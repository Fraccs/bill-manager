/*============================================================================
 * Name        : utils.c
 * Version     : v1.0.0
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 18/04/2022
 * Description : Source file containing multi-puropose functions declarations
 *============================================================================*/

#include "utils.h"

// Converts a char into a C string
char *utilsCharToString(char c) {
    char *str = malloc(sizeof(char) * 2);
    
    str[0] = c;
    str[1] = '\0';

    return str;
}