/*============================================================================
 * Name        : logs.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 24/11/2021
 * Description : Header containing logs related functions 
 *============================================================================*/

#ifndef _LOGS_H
#define _LOGS_H

#include <fstream>
#include "date.h"

// Logs the passed string to a txt, keeping track of the current machine time
void logToTxt(const std::string file_name, const std::string str);

#endif