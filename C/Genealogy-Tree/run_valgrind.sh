#!/bin/bash
PNAME="./main"

valgrind --leak-check=full --show-leak-kinds=all $PNAME < input
