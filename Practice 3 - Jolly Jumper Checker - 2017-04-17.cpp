//============================================================================
// Name        : Jolly Jumper Checker
// Author      : Martin Rivera
// Version     : 1
// Date Started: 2017-04-17
// Date Finished: 2017-04-21
// Description : Calculates if input is "Jolly Jumper:" a number sequence in which a set of the
//					differences between consecutive numbers in the sequence contains the same numbers as a consecutive
//					sequence from one to the size of the original sequence. i.e. if the original sequence has six elements,
//					the set made from the differences must contain the numbers 1, 2, 3, 4, and 5.
// Input	   : A string which begins with the size of the sequence to be evaluated, followed by the sequence, with each
//					number separated by a space i.e "6 3 1 6 5 2 6".
//============================================================================

#include <iostream>		// for cout
#include <string>		// for string
#include <vector>		// for vector
#include <algorithm>	// for sort

using namespace std;

// prototyping for absolute value function.
int abs(int in);

int main(int argc, char *argv[]) {
	string input = string(argv[1]);						// input sorting.
	int size = input[0] - '0';

	vector<int> members(size);							// vectors to contain the integers of the input members and the differences between them.
	vector<int> diffs(size-1);

	cout << "The sequence \"" << input;					// part of output to screen.
	int a = 0;											// Index "a" keeps track of the current place in "members" and "diffs," while index "i" keeps track of the position in the input string.
	for(int i = 1; i < (int)input.size(); i++){			// Populate "members" and "diffs" vectors
		if(input[i] != ' '){							// Checks to ignore
			members.at(a) = input[i] - '0';				// Lazy conversion from string to int.
			if(a > 0){									// only calculates numbers for "diffs" after the second member of "member" is populated.
				diffs.at(a - 1) = abs(members.at(a - 1) - members.at(a));	// Calculates difference between subsequent integers of the "members" vector and stores them in "diffs."
			}
			a++;
		}
	}

	cout << "\" is ";									// More output stuff.
	sort(diffs.begin(), diffs.end());					// Sorts "diffs" vector from smallest to largest.

	for(int i = 1; i < (int)diffs.size(); i++){			// Checks if the numbers in the sorted "diffs" are sequential.
		if(diffs.at(0) != 1){							// Checks if the sorted "diffs" starts with one. If it does not, the sequence is not "Jolly" and the program exits.
			cout << "NOT JOLLY\n";
			break;
		}else if(diffs.at(i-1) != diffs.at(i)-1){		// If any members in "diffs" are not sequential, the input is not "Jolly" and the program exits.
			cout << "NOT JOLLY\n";
			break;
		}else if(i == (int)diffs.size() - 1){			// If the search reaches the end of the sequence, the input was "Jolly" and the program exits.
			cout << "JOLLY";
		}
	}
	return 0;
}

// Absolute value function.
int abs(int in){
	if(in < 0){
		in = in * -1;
	}
	return in;
}
