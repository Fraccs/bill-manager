#!/bin/bash
# Downloading the latest binary
wget https://github.com/Fraccs/bill-manager/releases/download/v1.2.0/billman

# Giving the executable permission bit
chmod +x billman

# Moving the executable to the PATH
sudo mv billman /usr/local/bin

# Creating the group 'billman'
sudo groupadd billman

# Adding the current user to the group 'billman'
sudo usermod -aG billman $USER

# Creating the storage directory
sudo mkdir /var/lib/billman

# Changing the owner group of the storage directory
sudo chgrp billman /var/lib/billman

# Giving read/write/execute permission bits
sudo chmod g+rwx /var/lib/billman

# User login (to apply the changes)
su $USER -
