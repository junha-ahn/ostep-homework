#!/bin/bash

# Number of trials for each test case
num_trials=100000

# Loop to vary the number of pages accessed
for num_pages in 1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 16384; do
    echo ""
    echo "Running ./tlb $num_pages $num_trials"
    
    # Run the program for the current number of pages and print the results
    ./tlb $num_pages $num_trials
done