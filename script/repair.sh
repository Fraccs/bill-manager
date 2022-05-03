#!/bin/bash
# Directories and files
PATH="/usr/local/bin/"
BIN="billman"
STORAGE="/var/lib/billman/"

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

# Checking if the binary is in PATH
if test -f "$PATH$BIN"; then
    echo "$PASSED: '$BIN' is in PATH: '$PATH'${NC}"
else
    echo "$CRITICAL: '$BIN' is not in PATH: '$PATH'${NC}"
    echo "${YELLOW}Please run 'install.sh' with root permissions to repeat the installation process${NC}"
    exit
fi

# Checking for the executable bit
if test -x $PATH$BIN; then
    echo "$PASSED: '$BIN' is executable by '$USER'${NC}"
else
    echo "$ERROR: '$BIN' is not executable by '$USER'${NC}"
    echo "$FIXING: Adding the executable bit to '$BIN'${NC}"
    chmod +x $PATH$BIN
    echo "$FIXED: Added the executable bit to '$BIN'${NC}"
fi
