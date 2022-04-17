# **billmanager**

> ## *A simple command-line interface application written in C that helps you to manage your bills.*

## **Version**

> ### v0.0.1

## **How to compile**

> {compiler} -o bill_manager main.c .\src\bill.c .\src\client.c .\src\cli.c .\src\date.c .\src\echo.c .\src\help.c .\src\logs.c .\src\utils.c

> If 'make' is supported by your system, compile using 'make'. (Edit the included '[Makefile](https://github.com/Fraccs/bill-manager/blob/main/Makefile)' with the correct compiler, default=gcc).

## **Commands**

### ***bill --add***

* Creates a new bill.
* Flags:
    * -t (type):
        - Argument: Electricity; Gas; Phone; Water.  
    * -c (Cost)
        * Argument: Number.
    * -p (Paid):
        * Argument: No argument, if this flag is included, the bill is set as paid.
    * -d (Date): 
        * Argument: YYYY-MM-DD date format.
    * *Values for flags that aren't specified in the command will be set as default.*
* Example 1: bill --add -t Water -c 50 -d 2021-12-22
    * Result: Type=Water; Cost=50; Date=2021-12-22; Paid=false
* Example 2: bill --add -t Gas -c 100 -p
    * Result: Type=Gas; Cost=100; Date=Today; Paid=true

### ***bill --clear***
* Clears previous console output.

### ***bill --client***
* Prints the active client.

### ***bill --delete***
* Deletes a bill.
* Flags: 
    * -a (all):
        * Argument: NOARG.  
    * -n (file name)
        * Argument: file_name.
    * -c (deletes sclient)
        * Argument: NOARG.
* Example 1: bill --delete -a 
    * Result:
        * Deleted all bills in the client's directory (no echo).
* Example 2: bill --delete -n bill_name
    * Result:
        * Deleted the specified bill (no echo).

### ***bill --help***
* Prints the base help page of the program.

### ***bill --login username***
* Log in an existing client.
* Argument: username.

### ***bill --logout***
* Log out from the current client.

### ***bill --quit***
* Stops the execution of the program.

### ***bill --register username***
* Creates a new client (if it doesn't already exist).
* Argument: username.

### ***bill --view***
* Creates a new client (if it doesn't already exist).
* Flags: 
    * -n (file name):
        * Argument: Name of the bill to view. 
    * *If no flags are included in the command, the command prints all the bills in the client's directory.*
* Example 1: bill --view
    * Result: 
        * bill1.txt
        * bill2.txt
        * bill3.txt
* Example 2: bill --view -n bill_name
    * Result:  
        * Type: type
        * Cost: float
        * Usage: float
        * Paid: True/False
        * Paid in: YYYY-MM-DD
        * Due date: YYYY-MM-DD
