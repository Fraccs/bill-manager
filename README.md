# **Bill Manager**

> ## *A simple command-line application written in C that helps you to manage your bills.*

## **Version**

> ### v1.2.0

## **How to install**

> Download the install.sh script from the following link and execute it with root permissions ```$ sudo sh install.sh```

```bash
wget https://github.com/Fraccs/bill-manager/releases/download/v1.2.0/install.sh
```

## **How to repair a broken installation**

> Download the repair.sh script from the following link and execute it with root permissions ```$ sudo sh repair.sh```

```bash
wget https://github.com/Fraccs/bill-manager/releases/download/v1.1.0/repair.sh
```

## **How to compile**

> Compile using ```$ make```, edit the included [Makefile](https://github.com/Fraccs/bill-manager/blob/main/Makefile) with the correct compiler (default=gcc).

## **Commands**

### ***```$ billman --add <options>```***

> Creates a new bill.

Options:

* ```-t <type>``` (string):

    - ```type```: The type of bill (Water, Electricity...).  

* ```-c <cost>``` (float):
    
    * ```cost```: The cost of the bill.

* ```-e <due_date>``` (date):

    * ```due_date```: The expiry date in YYYY-MM-DD format.

* ```-d <paid_date>``` (date): 

    * ```paid_date```: The date the bill was paid in YYYY-MM-DD format, *it will automatically mark the bill as paid*.

* ```-p``` (bool):

    * *No argument required, if this flag is included, the bill is set as paid.*

* *If an option is not provided, its value is set as default.*

Example 1: ```$ billman --add -t Water -c 50```

* Result: Added the specified bill (no echo).

    * Type: Water
    * Cost: 50
    * Paid: False
    * Paid in: YYYY-MM-DD
    * Due date: YYYY-MM-DD

Example 2: ```$ billman --add -t Water -c 50 -d 2021-12-22```

* Result: Added the specified bill (no echo).

    * Type: Water
    * Cost: 50
    * Paid: True
    * Paid in: 2021-12-22
    * Due date: YYYY-MM-DD

Example 3: ```$ billman --add -t Gas -c 100 -p```

* Result: Added the specified bill (no echo).

    * Type: Gas
    * Cost: 100
    * Paid: True
    * Paid in: YYYY-MM-DD
    * Due date: YYYY-MM-DD

### ***```$ billman --delete <options>```***

> Deletes a bill.

Options: 

* ```-n <file_name>``` (Delete the bill 'file_name'):

    * ```file_name```: Name without '.bill'.

Example 1: ```$ billman --delete -n file_name```

* Result: Deleted the specified bill (no echo).

### ***```$ billman --help```***

> Prints the help page of the program.

### ***```$ billman --view <options>```***

> View the list of bills or the content of a bill.

Options: 

* ```-n <file_name>``` (View the content of the bill 'file_name'):

    * ```file_name```: Name without '.bill'.
    
* ```-a``` (View the list of bills):

    * *No argument*.

Example 1: ```$ billman --view -n bill1```

* Result:  
    * Type: type
    * Cost: float
    * Usage: float
    * Paid: True/False
    * Paid in: YYYY-MM-DD
    * Due date: YYYY-MM-DD

Example 2: ```$ billman --view -a```

* Result:  
    * YYYY-MM-DD-Phone.bill
    * YYYY-MM-DD-Electricity.bill
    * YYYY-MM-DD-Water.bill