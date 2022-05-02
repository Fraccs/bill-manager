/*============================================================================
 * Name        : utils.c
 * Version     : v1.2.0
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : 2022 Francesco Cristiano Aliprandi
 * License     : MIT
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