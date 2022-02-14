/*============================================================================
 * Name        : logs.c
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 14/02/2022
 * Description : Source file containing logs.h functions definition
 *============================================================================*/

#include "logs.h"

int logToTxt(char* file_name, char* str) {
    FILE* log_file;

    if(log_file == NULL) return -1; 

    // Appending to the last istance of the file 
    // log_file = fopen(file_name, "w"); 
    // fputs(machineTimeSecAccurate() + "|", log_file);
    // fputs(str, log_file);

    // log_file << machineTimeSecAccurate() << " | " << str << std::endl;

    // log_file.close();
}