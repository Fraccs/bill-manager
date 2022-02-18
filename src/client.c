/*============================================================================
 * Name        : client.c
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 18/02/2022
 * Description : Source file containing client related structs and functions definitions
 *============================================================================*/

#include "client.h"

/* Checks if another istance of username exists, 
if it doesn't it saves the username and password in 'clients.txt'*/
int registerClient(client* c, const char* username, const char* password) {
    FILE* client_file;
    // ifstream read;
    // ofstream write;
    char* temp;
    char* temp_user;

    if(strlen(username) < 3) return -1;
    if(c->logged_in) return -2;

    client_file = fopen("Data/clients.txt", "r");

    if(client_file == NULL) return -3;

    // Checking for other istances of username
    while(fscanf(client_file, "%[^\n]", temp)) {
        for(int i = 0; temp[i] != ' ' && temp[i] != '\0'; i++) {
            strcat(temp_user, temp[i]);

            if(temp_user == username) {
                return -4;
            }
        }
    }
    
    fclose(client_file);

    // Autologin
    c->username = username;
    c->password = password;
    c->logged_in = true;
    
    // Writing in the file
    client_file = fopen("Data/clients.txt", "w");
    printf("%s %s\n", username, password);
    fclose(client_file);

    // Creating a directory for 'username'
    mkdir(strcat("Data/", username), 0777);
}

/* Looks for username matches in 'clients.txt', 
if it finds one and the password is correct it logs-in the given client*/
int loginClient(client* c, const char* username, const char* password) {
    FILE* client_file;
    char* temp;
    char* temp_user, temp_pass;

    if(strlen(username) < 3) return -1;;
    if(c->logged_in) return -2;

    // Checking for other istances of username
    client_file = fopen("Data/clients.txt", "r");

    while(fscanf(client_file, "%[^\n]", temp)) {
        temp_user = "";
        temp_pass = "";

        for(int i = 0; temp[i] != ' ' && temp[i] != '\0'; i++) {
            strcat(temp_user, temp[i]);
        }

        for(int i = srtlen(temp_user) + 1; temp[i] != ' ' && temp[i] != '\0'; i++) {
            strcat(temp_pass, temp[i]);
        }

        if(strcmp(temp_user, username)) {
            if(strcmp(temp_pass, password)) {
                c->username = username;
                c->password = password;
                c->logged_in = true;
                return 0;
            }
            else {
                return -3;
            }
        }
    }
    
    fclose(client_file);

    // Client not found
    return -4;
}

//  Logout from the current client
int logoutClient(client* c) {
    if(c->username == "Default") return -1;

    c->username = "Default";
    c->password = "Default";
    c->logged_in = false;
}

// Adds the passed bill to the client's bill list
int addBill(client* c, bill b) {
    FILE* write;
    int num = 0;

    // auto file_iterator = filesystem::directory_iterator("Data/" + username + "/");

    // // Getting the number of files in the client's directory
    // for(auto& file: file_iterator) {
    //     if(file.is_regular_file()){
    //         num++;
    //     }
    // }

    // write.open("Data/" + username + "/bill" + to_string(num + 1) + ".txt", fstream::app);
    
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
   
    // fclose(write);

    return 0;
}

// Deletes all the bills of the logged client
void deleteAll(client* c) {
    // auto file_iterator = filesystem::directory_iterator("Data/" + username + "/");
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
    // char* temp;
    // char* path_string;
    // filesystem::path path;

    // auto file_iterator = filesystem::directory_iterator("Data/" + username + "/");

    // // Iterating through all the lines of all the files
    // for(auto& file: file_iterator) {
    //     if(file.is_regular_file()){
    //         // Getting file path (Data/User/bill.txt)
    //         path = file;
    //         // Path to char*             path_string = path.u8string();

    //         if(path_string == "Data/" + username + "/" + file_name + ".txt") {
    //             remove(path_string.c_str());
    //         }
    //     }
    // }
}

// Deletes the logged client
void deleteClient(client* c) {
    FILE* client_file;
    char* temp;
    char* temp_user;


    client_file = fopen("Data/clients.txt", "r");

    // Deleting client from clients.txt
    // while(getline(read, temp)) {
    //     for(int i = 0; temp[i] != ' '; i++) {
    //         temp_user.push_back(temp[i]);
    //     }

    //     if(temp_user == username) {
    //         write << "";
    //     }
    // }

    fclose(client_file);

    // Deleting client's folder
    deleteAll(c);
    // remove(("Data/" + username + "/").c_str());

    logoutClient(c);
}

// Prints the bills that match the flags
void viewAll(client* c) {
    // char* path_string;
    // filesystem::path path;

    // auto file_iterator = filesystem::directory_iterator("Data/" + username + "/");

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
    // char* temp;
    // char* path_string;
    // filesystem::path path;

    // auto file_iterator = filesystem::directory_iterator("Data/" + username + "/");

    // // Iterating through the directory
    // for(auto& file: file_iterator) {
    //     if(file.is_regular_file()){
    //         // Getting file path
    //         path = file;
    //         // Path to char*             path_string = path.u8string();

    //         if(path_string == "Data/" + username + "/" + file_name + ".txt") {
    //             read.open(path_string);

    //             while(getline(read, temp)) {
    //                 cout << temp << endl;
    //             }

    //             read.close();

    //             return 0;
    //         }
    //     }
    // }   

    // // Bill not found
    // return -1; 
}