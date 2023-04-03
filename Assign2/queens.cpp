/***************************************************************
CSCI 241         Program 3     spring 2020

Programmer: Trevor Berggrenz1906236

Section: Week 3

Date Due: 01/27/2021
***************************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

#define N 8

class queen_solver {			// Creats the queen class
	private:

		bool board[N][N] = {{false}};			// Sets the board to false which = 0

	public:							//Holds functions to be used 

		queen_solver() = default;
		bool place_queens();
		bool place_queen_in_row(int);
		bool is_safe(int, int) const;
		void print_solution() const;
};


int main() {						// Runs the program
	queen_solver q;

	if (q.place_queens())
		q.print_solution();
	else
		cout << "Error - no solution found\n";

	return 0;
}

bool queen_solver::place_queens() {				// Calls place queen in row to place queens
	return place_queen_in_row(0);
}


bool queen_solver::place_queen_in_row(int row) {			// Places a queen in a row using recusion

	// Base case #1
	if (row >= N)
		return true;

	for ( int col = 0; col < N; col++) {			// Base case 2 
		if (is_safe(row, col)) {
			board[row][col] = 1;

			if (place_queen_in_row(row + 1))
				return true;

			else
				board[row][col] = 0;
		}
	}
//base case 3 cannot place queen
	return false;
}

bool queen_solver::is_safe(int row, int col) const {				// Checks to see if it is safe to place a queen

	for (int i = 0; i < row; i++)
		if (board[i][col])
			return false;
	for (int i=row, j=col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;
	for (int i=row, j=col; i>= 0 && j < N; i--, j++)
		if (board[i][j])
			return false;
	return true;
}

void queen_solver::print_solution() const {			// Prints the board with queens on it
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
}
