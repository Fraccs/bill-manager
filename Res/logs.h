/*============================================================================
 * Name        : logs.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 22/11/2021
 * Description : Header containing logs related functions 
 *============================================================================*/

#pragma once

#include <fstream>
#include "date.h"

// Logs the passed string to a txt, keeping track of the current machine time
void logToTxt(const std::string file_name, const std::string str) {
    std::ofstream log_file;

    // Appending to the last istance of the file 
    log_file.open(file_name, std::fstream::app); 
    log_file << currentMachineTime() << " | " << str << std::endl;

    log_file.close();
}