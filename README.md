# **bill-manager**
>### *A simple application that helps you to manage your bills.*

## **Compilation**
> Compile using c++17 standard.

## **Commands**
### ***bill --add***
* Creates a new bill.
* Flags: 
    * -t (type):
        * Argument: Electricity; Gas; Phone; Water.  
    * -c (Cost)
        * Argument: Number.
    * -u -> Usage: (The amount used)
        * Argument: Number.
    * -p -> Paid: (If it was paid or not)
        * Argument: No argument, if this flag is included, the bill is set as paid.
    * -d -> Date: 
        * Argument: DDMMYYYY date format.
    * *If some flags aren't included in the command, the values will be set as default values.*
* Example 1: bill --add -t Water -c 50 -d 22122021
    * Result: Type=Water; Cost=50; Date=22/12/2021; Paid=false
* Example 2: bill --add -t Gas -c 100 -u 1000 -p
    * Result: Type=Gas; Cost=100; Date=Today; Paid=true

### ***bill --client***
* Prints the active client.

### ***bill --delete -t -d***
* Deletes a bill.

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