/*============================================================================
 * Name        : client.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 21/11/2021
 * Description : Header containing "Client" classes and sub classes
 *============================================================================*/

#pragma once

#include "bill.h"

class Client {
    private:
    std::string username;

    std::vector<Bill> bill_list;

    public:
    Client() {
        this->username = "";
    }

    Client(std::string username) {
        this->username = username;
    }
};