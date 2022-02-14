/*============================================================================
 * Name        : logs.cpp
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 12/02/2022
 * Description : Source file containing logs.hpp functions definition
 *============================================================================*/

#include "logs.hpp"

void logToTxt(const std::string file_name, const std::string str) {
    std::ofstream log_file;

    // Appending to the last istance of the file 
    log_file.open(file_name, std::fstream::app); 
    log_file << machineTimeSecAccurate() << " | " << str << std::endl;

    log_file.close();
}