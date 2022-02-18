/*============================================================================
 * Name        : logs.c
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 17/02/2022
 * Description : Source file containing logs related functions definition
 *============================================================================*/

#include "logs.h"

int logEvent(const char* logfile_name, const char* str) {
    FILE* log_file;
    char time_string[20];

    log_file = fopen(logfile_name, "w");

    if(log_file == NULL) return -1; 

    machineTimeSecAccurate(time_string);

    // Appending to the last istance of the file 
    fprintf(log_file, "%s | %s\n", time_string, str);
    
    fclose(log_file);

    return 0;
}