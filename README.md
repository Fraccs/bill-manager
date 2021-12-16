# **bill-manager**
> ### *A simple application that helps you to manage your bills.*

## **Compiler**
> Windows: (compiler) -std=c++17 -o bill_manager main.cpp .\Res\bill.cpp .\Res\client.cpp .\Res\command_interpreter.cpp .\Res\date.cpp .\Res\logs.cpp .\Res\help.cpp

> Unix: Compile using 'make'. (Edit the included '[Makefile](https://github.com/Fraccs/bill-manager/blob/main/Makefile)' with the correct compiler, default=g++).

## **Commands**
### ***bill --add***
* Creates a new bill.
* Flags: 
    * -t (type):
        * Argument: Electricity; Gas; Phone; Water.  
    * -c (Cost)
        * Argument: Number.
    * -u (Usage):
        * Argument: Number.
    * -p (Paid):
        * Argument: No argument, if this flag is included, the bill is set as paid.
    * -d (Date): 
        * Argument: YYYY-MM-DD date format.
    * If some flags aren't included in the command, the values will be set as default values.*
* Example 1: bill --add -t Water -c 50 -d 2021-12-22
    * Result: Type=Water; Cost=50; Date=2021-12-22; Paid=false
* Example 2: bill --add -t Gas -c 100 -u 1000 -p
    * Result: Type=Gas; Cost=100; Date=Today; Paid=true

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