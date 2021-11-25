/*============================================================================
 * Name        : client.h
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 25/11/2021
 * Description : Header containing "Client" classes and sub classes prototypes
 *============================================================================*/

#ifndef _CLIENT_H
#define _CLIENT_H

#include "bill.h"

class Client {
    private:
    std::string username;
    std::string password;
    std::vector<Bill> bill_list;

    // Exception strings
    const std::string INVALID_USERNAME = "Exception handled: username too short.";

    public:
    Client();

    Client(std::string username);

    // Set Client::username
    void setUsername(std::string username);

    // Set Client::password
    void setPassword(std::string password);
};

#endif