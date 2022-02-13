/*============================================================================
 * Name        : logs.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 12/02/2022
 * Description : Header containing logs related functions declarations
 *============================================================================*/

#ifndef _LOGS_HPP
#define _LOGS_HPP

#include <fstream>
#include "date.hpp"

// Logs the passed string to a txt, keeping track of the current machine time
void logToTxt(const std::string file_name, const std::string str);

#endif