/*============================================================================
 * Name        : logs.cpp
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 23/11/2021
 * Description : Source file containing logs.h functions bodies
 *============================================================================*/

#include "logs.h"

void logToTxt(const std::string file_name, const std::string str) {
    std::ofstream log_file;

    // Appending to the last istance of the file 
    log_file.open(file_name, std::fstream::app); 
    log_file << currentMachineTime() << " | " << str << std::endl;

    log_file.close();
}