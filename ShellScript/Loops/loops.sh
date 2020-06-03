#!/bin/bash

BASE_IP="10.22.10"
NUMBER_OF_MACHINES=20

for NUMBER in $(seq 1 $NUMBER_OF_MACHINES); do
	CURRENT_MACHINE_IP="${BASE_IP}.${NUMBER}"
	
	# Do something here ...	
	echo "$CURRENT_MACHINE_IP"
done

