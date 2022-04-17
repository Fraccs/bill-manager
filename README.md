# **Bill Manager**

> ## *A simple command-line interface application written in C that helps you to manage your bills.*

## **Version**

> ### v1.0.0

## **How to compile**

> Compile using 'make'. (Edit the included '[Makefile](https://github.com/Fraccs/bill-manager/blob/main/Makefile)' with the correct compiler, default=gcc).

## **Commands**

### ***billman --add {parameters}***

> Creates a new bill.

* Parameters:
    * -t (type):
        - Argument: The type of bill (Water, Electricity...).  
    
    * -c (Cost)
        * Argument: The cost of the bill.
    
    * -p (Paid):
        * Argument: No argument required, if this flag is included, the bill is set as paid.
    
    * -d (Date): 
        * Argument: Date in YYYY-MM-DD format.
    
    * *If any parameter is not provided it will be set as default.*

* Example 1: billman --add -t Water -c 50 -d 2021-12-22
    * Result: Type=Water; Cost=50; Date=2021-12-22; Paid=false

* Example 2: billman --add -t Gas -c 100 -p
    * Result: Type=Gas; Cost=100; Date=Today; Paid=true

### ***billman --clear***

> Clears previous console output.

### ***billman --client***

> Prints the active client.

### ***billman --delete {parameters}***

> Deletes a bill.

* Parameters: 
    * -a (all):
        * Argument: No argument required, if the flag is included every bill of the client is deleted.

    * -n (name):
        * Argument: The name of the bill to delete.

* Example 1: bill --delete -a 
    * Result: Deleted all bills in the client's directory (no echo).

* Example 2: bill --delete -n bill_name
    * Result: Deleted the specified bill (no echo).

### ***billman --help***

> Prints the base help page of the program.

### ***billman --login {username}***

> Log in an existing client.

### ***billman --logout***

> Log out from the current client.

### ***billman --quit***

> Quit the program.

### ***billman --register {username}***

> Creates a new client (if it doesn't already exist).

### ***billman --view {arguments}***

> Prints the content of a bill / the list of bills owned by the client.

* Arguments: 
    * -n (file name):
        * Argument: Name of the bill to view. 
    
    * *If no flags are included in the command, the command prints all the bills in the client's directory.*

* Example 1: bill --view
    * Result: 
        * bill1.txt
        * bill2.txt
        * bill3.txt

* Example 2: bill --view -n bill1
    * Result:  
        * Type: type
        * Cost: float
        * Usage: float
        * Paid: True/False
        * Paid in: YYYY-MM-DD
        * Due date: YYYY-MM-DD
