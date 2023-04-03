/***************************************************************
CSCI 241         Program 3     spring 2020

Programmer: Trevor Berggrenz1906236

Section: Week 3 Hanoi

Date Due: 01/27/2021
***************************************************************/
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <string>

using std::stoi;
using namespace std;

void move(int,int,int,int);

int main(int argc, char* argv[]) {
	int n_disks;

	if(argc ==1) {					// Checks to see if data has a argument
		cout <<"Missing argument\n"
		     << "Usage hanoi number-of-disks\n";
		exit(1);
	}
	for( int i= 0; argv[1][i] != '\0'; i++) {		// Checks to see if it is a digit
		if (!isdigit(argv[1][i])) {
			cout << " Argument must be a number\n"
			<< "Usage hanoi number-of-disks\n";
			exit(1);
		}
	}
	n_disks = stoi(argv[1]);				//  Converts n_disks to a interger
	
	move(n_disks,1,2,3);					//Calls move function
	return 0;
	
	}
	
	void move(int n_disks,int src_peg, int dest_peg,int temp_peg)			//  Move function that moves the disks to pegs
	{
		if (n_disks >= 1)				// Base case if there are no disks to move
		{
			move(n_disks -1,src_peg,temp_peg,dest_peg);			// Moves the disks
			cout << n_disks << " " << src_peg<< "->" << dest_peg << endl;	// Displays results to user
			move(n_disks -1,temp_peg,dest_peg,src_peg);			// Moves disks if needed
			
		}
		
}

