/*============================================================================
 * Name        : logs.c
 * Version     : v0.0.1
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 04/03/2022
 * Description : Source file containing logs related functions definition
 *============================================================================*/

#include "logs.h"

int logEvent(const char *logfile_name, const char *str) {
    FILE* log_file;
    char time_string[20];

    log_file = fopen(logfile_name, "a+");

    if(log_file == NULL) return -1; 

    dateSecAccurate(time_string, 19);

    // Appending to the last istance of the file 
    fprintf(log_file, "%s | %s\n", time_string, str);
    
    fclose(log_file);

    return 0;
}