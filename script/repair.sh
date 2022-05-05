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
    
    $SUDO $CHMOD "+x" $PATH$BIN # chmod +x
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

