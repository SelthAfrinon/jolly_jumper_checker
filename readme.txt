Program: Jolly Jumper Checker
Author: Martin Rivera
Date: 2017-05-08

Description: Checks if an input sequence of numbers is a "Jolly Jumper" sequence. A "Jolly Jumper" sequence is a sequence where the difference between subsequent numbers form a set which contains all numbers from one to the size of the input sequence. 

Inputs: <sequence_of_numbers_seperated_by_spaces>
Note on inputs: Each input sequence must begin with the size of the subsequent sequence as an integer.

Output: Prints whether the input sequence is "Jolly" to the screen.

Process: Takes an input sequence of numbers and places them in the vector "members." The "diffs" vector is populated by the differences between subsequent elements in the "members" vector. The "diffs" vector is sorted: if each subsequent member of the sorted "diffs" vector is equal to the previous member plus one and the first member of the vector is "1," the sequence is "Jolly." The program checks if the sorted "diffs" vector for the aformentioned requirements and prints to screen if the input sequence is "Jolly" or not.
