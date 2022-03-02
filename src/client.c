/*============================================================================
 * Name        : client.c
 * Version     : Alpha
 * Since       : 2021
 * Author      : Aliprandi Francesco <aliprandifrancescopp@gmail.com>
 * Web         : https://github.com/Fraccs/bill-manager
 * Copyright   : N/D
 * License     : N/D
 * Last change : 28/02/2022
 * Description : Source file containing client related structs and functions definitions
 *============================================================================*/

#include "client.h"

/* Client struct, note that this is an opaque type and only pointer declaration is valid.
Use the predefined functions to access members */
typedef struct cs {
    char username[USER_MAXLEN + 1];
    char password[PASS_MAXLEN + 1];
    bool logged_in;
} client;

// Returns a pointer to the memory allocated on the heap for a new client
client *clientCreate() {
    client *c = malloc(sizeof(client)); 

    if(c == NULL) return NULL;

    memset(c->username, 0, USER_MAXLEN + 1);
    memset(c->password, 0, PASS_MAXLEN + 1);

    strcpy(c->username, "default");
    strcpy(c->password, "default");
    c->logged_in = false;

    return c;
}

// Frees the memory of the passed client
int clientDestroy(client *c) {
    if(c == NULL) return -1;

    free(c);

    return 0;
}

/* Checks if another instance of username exists, 
if it doesn't, it saves the username and password in 'clients.txt' */
int clientRegister(client *c, const char *username, const char *password) {
    FILE *f_handle;
    char line[USER_MAXLEN + PASS_MAXLEN + 1];
    char temp_user[USER_MAXLEN + 1];
    char path[USER_MAXLEN + 6] = "data/";
    char log_string[LOGS_MAXLEN + 1];

    memset(line, 0, USER_MAXLEN + PASS_MAXLEN + 1);
    memset(temp_user, 0, USER_MAXLEN + 1);
    memset(log_string, 0, LOGS_MAXLEN + 1);

    if(strlen(username) < 3) return -1;
    if(strlen(password) < 6) return -1;
    if(c->logged_in) return -1;

    /* ---- Register mechanism ---- */
    f_handle = fopen("data/clients.txt", "a+");

    if(f_handle == NULL) return -1;

    /* ---- Checking if the username already exists ---- */
    while(fgets(line, USER_MAXLEN + PASS_MAXLEN, f_handle)) {
        for(int i = 0; line[i] != ' ' && line[i] != '\0'; i++) {
            strncat(temp_user, utilsCharToString(line[i]), USER_MAXLEN);

            if(strncmp(temp_user, username, USER_MAXLEN) == 0) {
                fclose(f_handle);
                return -1; // Found same username
            }
        }

        memset(temp_user, 0, USER_MAXLEN + 1);
    }
    
    /* ---- Saving the new client ---- */
    fprintf(f_handle, "%s %s\n", username, password);
    fclose(f_handle);

    /* ---- New client's directory ---- */
    #ifdef _WIN32
    CreateDirectory(strcat(path, username), NULL);
    #else
    if(mkdir(strcat(path, username), S_IRWXU) == -1) return -1;
    #endif

    /* ---- Logging registration success ---- */
    strncat(log_string, "Client '", LOGS_MAXLEN);
    strncat(log_string, username, LOGS_MAXLEN);
    strncat(log_string, "' registered successfully.", LOGS_MAXLEN);

    logEvent("logs.txt", log_string);

    return 0;
}

/* Looks for username matches in 'clients.txt', 
if it finds one and the password is correct it logs-in the given client */
int clientLogin(client *c, const char *username, const char *password) {
    FILE *f_handle;
    char line[USER_MAXLEN + PASS_MAXLEN + 1];
    char temp_user[USER_MAXLEN + 1];
    char temp_pass[PASS_MAXLEN + 1];
    char log_string[LOGS_MAXLEN + 1];

    memset(line, 0, USER_MAXLEN + PASS_MAXLEN + 1);
    memset(temp_user, 0, USER_MAXLEN + 1);
    memset(temp_pass, 0, PASS_MAXLEN + 1);
    memset(log_string, 0, LOGS_MAXLEN + 1);

    if(strlen(username) < 3 || strlen(username) > 10) return -1;
    if(strlen(password) < 6 || strlen(username) > 20) return -1;
    if(c->logged_in) return -1;

    /* ---- Login mechanism ---- */
    f_handle = fopen("data/clients.txt", "r");

    if(f_handle == NULL) return -1;

    while(fgets(line, USER_MAXLEN + PASS_MAXLEN, f_handle)) {
        /* ----- Get username from line ---- */
        for(int i = 0; line[i] != ' ' && line[i] != '\0'; i++) {
            strncat(temp_user, utilsCharToString(line[i]), USER_MAXLEN);
        }

        /* ----- Get password from line ---- */
        for(int i = strlen(temp_user) + 1; line[i] != ' ' && line[i] != '\0'; i++) {
            strncat(temp_pass, utilsCharToString(line[i]), PASS_MAXLEN);
        }

        /* ---- Comparing with login input ---- */
        if(strncmp(temp_user, username, USER_MAXLEN) == 0) {
            if(strncmp(temp_pass, password, PASS_MAXLEN) == 0) {
                strncpy(c->username, username, USER_MAXLEN);
                strncpy(c->password, password, PASS_MAXLEN);
                c->logged_in = true;
                
                fclose(f_handle);

                /* ---- Logging login success ---- */
                strncat(log_string, "Client '", LOGS_MAXLEN);
                strncat(log_string, username, LOGS_MAXLEN);
                strncat(log_string, "' logged in successfully.", LOGS_MAXLEN);

                logEvent("logs.txt", log_string);

                return 0; // Successful login
            }
            else {
                fclose(f_handle);

                /* ---- Logging login failure ---- */
                strncat(log_string, "Unsuccessful login for client '", LOGS_MAXLEN);
                strncat(log_string, username, LOGS_MAXLEN);
                strncat(log_string, "', wrong password.", LOGS_MAXLEN);

                logEvent("logs.txt", log_string);

                return -1; // Wrong password
            }
        }

        memset(temp_user, 0, USER_MAXLEN + 1);
        memset(temp_pass, 0, PASS_MAXLEN + 1);
    }
    
    fclose(f_handle);

    /* ---- Logging login failure ---- */
    strncat(log_string, "Unsuccessful login, client '", LOGS_MAXLEN);
    strncat(log_string, username, LOGS_MAXLEN);
    strncat(log_string, "' not found.", LOGS_MAXLEN);

    logEvent("logs.txt", log_string);

    return -1; // Client not found
}

// Logout from the current client
int clientLogout(client *c) {
    char log_string[LOGS_MAXLEN + 1];

    memset(log_string, 0, LOGS_MAXLEN + 1);

    if((strcmp(c->username, "default") == 0) || (!c->logged_in)) return -1;
 
    /* ---- Logging logout success ---- */
    strncat(log_string, "Client '", LOGS_MAXLEN);
    strncat(log_string, c->username, LOGS_MAXLEN);
    strncat(log_string, "' successfully logged out.", LOGS_MAXLEN);

    logEvent("logs.txt", log_string);

    /* ---- Logout ---- */
    strcpy(c->username, "default");
    strcpy(c->password, "default");
    c->logged_in = false;

    return 0;
}

// Adds the passed bill to the client's bill list
int clientAddBill(client *c, bill *b) {
    FILE *f_handle;
    char path[PATH_MAXLEN + 1];

    memset(path, 0, PATH_MAXLEN + 1);

    /* ---- New bill path ---- */
    strncat(path, "data/", PATH_MAXLEN); // data/ 
    strncat(path, clientGetUsername(c), PATH_MAXLEN); // data/username
    strncat(path, "/", PATH_MAXLEN); // data/username/
    strncat(path, dateEpochSeconds(), PATH_MAXLEN); // data/username/EPOCH_SECONDS
    strncat(path, ".txt", PATH_MAXLEN); // data/username/EPOCH_SECONDS.txt

    /* ---- Writing onto the file ---- */
    f_handle = fopen(path, "a");
    
    if(f_handle == NULL) return -1;
    
    fprintf(f_handle, "Type: %s\n", billGetType(b));
    fprintf(f_handle, "Cost: %f\n", billGetCost(b));

    if(billGetPaid(b)) {
        fprintf(f_handle, "Paid: True\n");
    }
    else {
        fprintf(f_handle, "Paid: False\n");
    }

    fprintf(f_handle, "Paid in: %s\n", billGetPaidDate(b));
    fprintf(f_handle, "Due date: %s\n", billGetDueDate(b));
   
    fclose(f_handle);

    return 0;
}

// Deletes all the bills of the logged client
void clientDeleteAll(client *c) {
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

// Deletes the passed bill from the client's directory
int clientDeleteBill(client *c, const char *file_name) {
    char path[PATH_MAXLEN + 1];
    int ret; // Error checking

    memset(path, 0, PATH_MAXLEN + 1);

    /* ---- File path ---- */
    strncat(path, "data/", PATH_MAXLEN); // data/ 
    strncat(path, clientGetUsername(c), PATH_MAXLEN); // data/username
    strncat(path, "/", PATH_MAXLEN); // data/username/
    strncat(path, file_name, PATH_MAXLEN); // data/username/file_name
    strncat(path, ".txt", PATH_MAXLEN); // data/username/file_name.txt

    ret = remove(path);

    if(ret == -1) return ret;

    return 0;
}

// // Deletes the logged client
// void clientDelete(client* c) {
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
void clientViewAll(client *c) {
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
int clientViewBill(client *c, const char *file_name) {
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

// Returns the username of the passed client
char *clientGetUsername(client *c) {
    if(c == NULL) return NULL;

    return c->username;
}

// Returns the password of the passed client
char *clientGetPassword(client *c) {
    if(c == NULL) return NULL;

    return c->password;
}

// Returns if the passed client is logged-in or not
int clientGetLoggedin(client *c) {
    if(c == NULL) return -1;
    
    return c->logged_in;
}