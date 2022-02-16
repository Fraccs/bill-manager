/*============================================================================
 * Name        : logs.c
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 16/02/2022
 * Description : Source file containing logs related functions definition
 *============================================================================*/

#include "logs.h"

int logToTxt(char* file_name, char* str) {
    FILE* log_file;

    log_file = fopen(file_name, "w");

    if(log_file == NULL) return -1; 

    // Appending to the last istance of the file 
    fprintf(log_file, "%s | %s", machineTimeSecAccurate(), str);
    
    fclose(log_file);

    return 0;
}