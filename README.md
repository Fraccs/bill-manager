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
    
    * -e (The expiry date):
        * Argument: Date in YYYY-MM-DD format.

    * -d (The day when it was paid): 
        * Argument: Date in YYYY-MM-DD format, *it will automatically mark the bill as paid*.
    
    * *If any parameter is not provided, its value is set as default.*

* Example 1: ```$ billman --add -t Water -c 50```
    * Result: Type=Water; Cost=50;

* Example 2: ```$ billman --add -t Water -c 50 -d 2021-12-22```
    * Result: Type=Water; Cost=50; Date=2021-12-22; Paid=True

* Example 3: ```$ billman --add -t Gas -c 100 -p```
    * Result: Type=Gas; Cost=100; Date=Today; Paid=true

### ***billman --delete {parameters}***

> Deletes a bill.

* Parameters: 
    * -n (name):
        * Argument: The name of the bill to delete.

* Example 1: ```$ billman --delete -n bill_name```
    * Result: Deleted the specified bill (no echo).

### ***billman --help***

> Prints the help page of the program.

### ***billman --view {arguments}***

> Prints the content of a bill.

* Parameters: 
    * -n (file name):
        * Argument: Name of the bill to view. 
    
    * -a (all):
        * Argument: No argument.

* Example 1: ```$ billman --view -n bill1```
    * Result:  
        * Type: type
        * Cost: float
        * Usage: float
        * Paid: True/False
        * Paid in: YYYY-MM-DD
        * Due date: YYYY-MM-DD
