#!/bin/bash
# Directories and files
PATH="/usr/local/bin/"
BIN="billman"
STORAGE="/var/lib/billman/"
GROUP="billman"

# Command PATHS
SUDO="/usr/bin/sudo"
GROUPADD="/usr/sbin/groupadd"
CHMOD="/usr/bin/chmod"
GREP="/usr/bin/grep"
GROUPS="/usr/bin/groups"
USERMOD="/usr/sbin/usermod"
ID="/usr/bin/id"
MKDIR="/usr/bin/mkdir"
LS="/usr/bin/ls"
CHGRP="/usr/bin/chgrp"

# Colors
GREEN='\033[1;32m'
YELLOW='\033[1;33m'
RED='\033[1;31m'
NC='\033[0m' # No Color

# Check status
PASSED="${GREEN}Passed [v]"
FIXED="${GREEN}Fixed [v]"
FIXING="${YELLOW}Fixing [f]"
ERROR="${RED}Error [x]"
CRITICAL="${RED}Critical [X]"
ABORT="${RED}Aborting."

# Checking if the binary is in PATH
if test -f "$PATH$BIN"; then
    echo "$PASSED: '$BIN' is in PATH: '$PATH'${NC}"
else
    echo "$CRITICAL: '$BIN' is not in PATH: '$PATH'${NC}"
    echo "${YELLOW}Please run 'install.sh' with root permissions and repeat the installation${NC}"
    echo $ABORT
    exit
fi

# Checking for the executable bit
if test -x $PATH$BIN; then
    echo "$PASSED: '$BIN' is executable by '$USER'${NC}"
else
    echo "$ERROR: '$BIN' is not executable by '$USER'${NC}"
    echo "$FIXING: Adding the executable bit to '$BIN'${NC}"
    
    $SUDO $CHMOD "+x" $PATH$BIN # chmod +x $PATH$BIN
    echo "$FIXED: Added the executable bit to '$BIN'${NC}"
fi

# Checking if group 'billman' exists
if $GREP -q $GROUP /etc/group; then
    echo "$PASSED: the group '$GROUP' exists${NC}"
else
    echo "$ERROR: the group '$GROUP' does not exist${NC}"
    echo "$FIXING: Creating the group '$GROUP'${NC}" 

    $SUDO $GROUPADD $GROUP # groupadd billman
    echo "$FIXED: Created the group '$GROUP'${NC}"
fi

# Checking if user is in the 'billman' group
if $ID -nG "$USER" | $GREP -qw "$GROUP"; then
    echo "$PASSED: '$USER' is in the group '$GROUP'${NC}"
else
    echo "$ERROR: '$USER' is not in the group '$GROUP'${NC}"
    echo "$FIXING: Adding '$USER' to the group '$GROUP'${NC}" 

    $SUDO $USERMOD -aG $GROUP $USER # usermod -aG billman $USER
    echo "$FIXED: Created the group '$GROUP'${NC}"
fi

# Checking if the storage directory exists
if [ -d $STORAGE ]; then
    echo "$PASSED: the storage directory '$STORAGE' exists${NC}"
else
    echo "$ERROR: the storage directory '$STORAGE' does not exist${NC}"
    echo "$FIXING: Creating the storage directory '$STORAGE'${NC}" 

    $SUDO $MKDIR $STORAGE # mkdir /var/lib/billman
    echo "$FIXED: Created the storage directory '$STORAGE'${NC}"
fi

# Checking if the 'billman' group is the owner of the storage directory
if $LS "/var/lib" -l | $GREP -qw "$GROUP"; then
    echo "$PASSED: the group '$GROUP' is the owner of the storage directory '$STORAGE'${NC}"
else
    echo "$ERROR: the group '$GROUP' is not the owner of the storage directory '$STORAGE'${NC}"
    echo "$FIXING: Changing the owner group of the storage directory '$STORAGE'${NC}" 

    $SUDO $CHGRP $GROUP $STORAGE # chgrp billman /var/lib/billman
    echo "$FIXED: Changed the owner group of storage directory '$STORAGE'${NC}"
fi

# Checking if the 'billman' group has permissions over the storage directory
if test -r $STORAGE && test -w $STORAGE && test -x $STORAGE; then
    echo "$PASSED: the group '$GROUP' has permissions over the storage directory '$STORAGE'${NC}"
else
    echo "$ERROR: the group '$GROUP' does not have permissions over the storage directory '$STORAGE'${NC}"
    echo "$FIXING: Adding permissions to the group '$GROUP' over the storage directory '$STORAGE'${NC}" 

    $SUDO $CHMOD g+rwx $STORAGE # chmod g+rwx /var/lib/billman
    echo "$FIXED: Added permissions to the group '$GROUP' over the storage directory '$STORAGE'${NC}"
fi
