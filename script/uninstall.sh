#!/bin/bash
# Removing the executable from the PATH
sudo rm /usr/local/bin/billman

# Deleting the group 'billman'
sudo groupdel billman

# Removing the storage directory
sudo rm -r /var/lib/billman
