/*============================================================================
 * Name        : client.c
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 19/02/2022
 * Description : Source file containing client related structs and functions definitions
 *============================================================================*/

#include "client.h"

/* Checks if another instance of username exists, 
if it doesn't it saves the username and password in 'clients.txt'*/
int registerClient(client* c, const char* username, const char* password) {
    FILE* f_handle;
    char line[USER_MAXLEN + PASS_MAXLEN + 1];
    char temp_user[USER_MAXLEN + 1];

    memset(line, 0, USER_MAXLEN + PASS_MAXLEN);
    memset(temp_user, 0, USER_MAXLEN);

    if(strnlen(username, USER_MAXLEN) < 3) return -1;
    if(strnlen(password, PASS_MAXLEN) < 6) return -1;
    if(c->logged_in) return -1;

    f_handle = fopen("data/clients.txt", "r");

    if(f_handle == NULL) return -1;

    // Checking for the existence of username
    while(fscanf(f_handle, "%[^\n]", line)) {
        for(int i = 0; line[i] != ' ' && line[i] != '\0'; i++) {
            strncat(temp_user, line[i], USER_MAXLEN);

            if(strncmp(temp_user, username, USER_MAXLEN)) {
                return -1;
            }
        }
    }
    
    fclose(f_handle);

    // Autologin
    loginClient(c, username, password);
    
    // Writing in the file
    f_handle = fopen("data/clients.txt", "w");
    fprintf(f_handle, "%s %s\n", username, password);
    fclose(f_handle);

    // Creating a directory for 'username'
    mkdir(strcat("data/", username), 0777);

    return 0;
}

/* Looks for username matches in 'clients.txt', 
if it finds one and the password is correct it logs-in the given client*/
int loginClient(client* c, const char* username, const char* password) {
    FILE* f_handle;
    char line[USER_MAXLEN + PASS_MAXLEN + 1];
    char temp_user[USER_MAXLEN + 1];
    char temp_pass[PASS_MAXLEN + 1];

    memset(line, 0, USER_MAXLEN + PASS_MAXLEN);
    memset(temp_user, 0, USER_MAXLEN);
    memset(temp_pass, 0, PASS_MAXLEN);

    if(strnlen(username, USER_MAXLEN) < 3) return -1;
    if(strnlen(password, PASS_MAXLEN) < 6) return -1;
    if(c->logged_in) return -1;

    // Checking for other istances of username
    f_handle = fopen("data/clients.txt", "r");

    while(fscanf(f_handle, "%[^\n]", line)) {
        for(int i = 0; line[i] != ' ' && line[i] != '\0'; i++) {
            strncat(temp_user, line[i], USER_MAXLEN);
        }

        for(int i = srtlen(temp_user) + 1; line[i] != ' ' && line[i] != '\0'; i++) {
            strncat(temp_pass, line[i], PASS_MAXLEN);
        }

        if(strncmp(temp_user, username, USER_MAXLEN)) {
            if(strncmp(temp_pass, password, PASS_MAXLEN)) {
                strncmp(c->username, username, USER_MAXLEN);
                strncmp(c->password, password, PASS_MAXLEN);
                c->logged_in = true;
                return 0;
            }
            else {
                return -1;
            }
        }
    }
    
    fclose(f_handle);

    // Client not found
    return -1;
}

//  Logout from the current client
int logoutClient(client* c) {
    if(strncmp(c->username, "default", USER_MAXLEN)) return -1;
    if(!c->logged_in) return -1;
 
    strncpy(c->username, "default", USER_MAXLEN);
    strncpy(c->password, "default", PASS_MAXLEN);
    c->logged_in = false;

    return 0;
}

// Adds the passed bill to the client's bill list
int addBill(client* c, bill b) {
    FILE* f_handle;
    int num = 0;

    // auto file_iterator = filesystem::directory_iterator("data/" + username + "/");

    // // Getting the number of files in the client's directory
    // for(auto& file: file_iterator) {
    //     if(file.is_regular_file()){
    //         num++;
    //     }
    // }

    // write.open("data/" + username + "/bill" + to_string(num + 1) + ".txt", fstream::app);
    
    // if(write == NULL) return -1;

    // fprintf(write, "Type: %s\nCost: %f\nUsage: %f\n", bill.type, bill.cost, bill.usage);

    // if(bill.getPaid()) {
    //     write << "Paid: True" << endl;
    // }
    // else {
    //     write << "Paid: False" << endl;
    // }

    // write << "Paid in: " << bill.getPaidDate() << endl;
    // write << "Due date: " << bill.getDueDate() << endl;
   
    fclose(f_handle);

    return 0;
}

// Deletes all the bills of the logged client
void deleteAll(client* c) {
    // auto file_iterator = filesystem::directory_iterator("data/" + username + "/");
    // char* path_string;
    // filesystem::path path;

    // // Iterating through all the lines of all the files
    // for(auto& file: file_iterator) {
    //     if(file.is_regular_file()){
    //         // Getting file path
    //         path = file;
    //         // Path to char*             path_string = path.u8string();

    //         remove(path_string.c_str());            
    //    }
    // }
}

// Deletes the passed bill from the client's bill list
void deleteBill(client* c, const char* file_name) {
    // char* line;
    // char* path_string;
    // filesystem::path path;

    // auto file_iterator = filesystem::directory_iterator("data/" + username + "/");

    // // Iterating through all the lines of all the files
    // for(auto& file: file_iterator) {
    //     if(file.is_regular_file()){
    //         // Getting file path (data/User/bill.txt)
    //         path = file;
    //         // Path to char*             path_string = path.u8string();

    //         if(path_string == "data/" + username + "/" + file_name + ".txt") {
    //             remove(path_string.c_str());
    //         }
    //     }
    // }
}

// // Deletes the logged client
// void deleteClient(client* c) {
//     FILE* f_handle;
//     char* line;
//     char* temp_user;


//     f_handle = fopen("data/clients.txt", "r");

//     // Deleting client from clients.txt
//     // while(getline(read, line)) {
//     //     for(int i = 0; line[i] != ' '; i++) {
//     //         temp_user.push_back(line[i]);
//     //     }

//     //     if(temp_user == username) {
//     //         write << "";
//     //     }
//     // }

//     fclose(f_handle);

//     // Deleting client's folder
//     deleteAll(c);
//     // remove(("data/" + username + "/").c_str());

//     logoutClient(c);
// }

// Prints the bills that match the flags
void viewAll(client* c) {
    // char* path_string;
    // filesystem::path path;

    // auto file_iterator = filesystem::directory_iterator("data/" + username + "/");

    // // Iterating through the directory
    // for(auto& file: file_iterator) {
    //     if(file.is_regular_file()){
    //         // Getting file path
    //         path = file;
    //         // Path to char*             
    //         path_string = path.u8string();

    //         printf("%s", path_string)
    //     }
    // }   
}

// Prints the content of a bill
int viewBill(client* c, const char* file_name) {
    // FILE* read;
    // char* line;
    // char* path_string;
    // filesystem::path path;

    // auto file_iterator = filesystem::directory_iterator("data/" + username + "/");

    // // Iterating through the directory
    // for(auto& file: file_iterator) {
    //     if(file.is_regular_file()){
    //         // Getting file path
    //         path = file;
    //         // Path to char*             path_string = path.u8string();

    //         if(path_string == "data/" + username + "/" + file_name + ".txt") {
    //             read.open(path_string);

    //             while(getline(read, line)) {
    //                 cout << line << endl;
    //             }

    //             read.close();

    //             return 0;
    //         }
    //     }
    // }   

    // // Bill not found
    // return -1; 
}