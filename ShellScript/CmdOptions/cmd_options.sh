#!/bin/bash

# Bash function
PRINT_USAGE () { 
	echo "----------------------------------------------------------------------------"	
	echo "Usage $0 [flags] [modules]" >&2;
	echo "----------------------------------------------------------------------------"
	echo "Valid modules: all, gui, simulator or batch (default is all)" >&2;
	echo "Valid flags:" >&2;
	echo "-a  - flag 'a' option" >&2;
	echo "-b  - flag 'b' option" >&2;
	echo "-c  - flag 'c' option" >&2;
	echo "----------------------------------------------------------------------------"
	exit 1
}

# Program options variables (default is everything disable)
FLAG_A='n'
FLAG_B='n'
FLAG_C='n'

# Initialize the option parser index
OPTIND=1

while getopts "h?abc" opt; do
	case "$opt" in
     		h|\?) PRINT_USAGE "$@" ;;
		a) FLAG_A='y'; echo "Running command with flag 'a' on !" ;;
		b) FLAG_B='y'; echo "Running command with flag 'b' on !" ;;
		c) FLAG_C='y'; echo "Running command with flag 'c' on !" ;;
    	esac
done

shift $((OPTIND-1))

# Examples:
#	$ ./cmd_options.sh -h
#	$ ./cmd_options.sh -a
#	$ ./cmd_options.sh -a -b -c
