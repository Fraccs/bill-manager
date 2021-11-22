/*============================================================================
 * Name        : logs.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 21/11/2021
 * Description : Header containing logs related functions 
 *============================================================================*/

#include <fstream>
#include "date.h"

// Logs the passed string to a txt
void logToTxt(const std::string file_name, const std::string str) {
    std::ofstream log_file;

    // Appending to the last istance of the file 
    log_file.open(file_name, std::fstream::app); 
    log_file << currentDateTime() << str << std::endl;

    log_file.close();
}