/*============================================================================
 * Name        : client.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 23/11/2021
 * Description : Header containing "Client" classes and sub classes
 *============================================================================*/

#ifndef _CLIENT_H
#define _CLIENT_H

#include "bill.h"

class Client {
    private:
    std::string username;
    std::vector<Bill> bill_list;

    public:
    Client();

    Client(std::string username);
};

#endif