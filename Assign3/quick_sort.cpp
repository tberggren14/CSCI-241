/***************************************************************
CSCI 241         Program 3     spring 2020

Programmer: Trevor Berggrenz1906236

Section: Week 4

Date Due: 02/04/2021
***************************************************************/

#include <iostream>
#include <iomanip>
#include <utility>

using namespace std;

int build_array(int[]);
void quick_sort(int[], int, int);
void print_array(int[], int);
int partition(int[], int,int);

int main() {								// Driver function
	int array[1000];
	int n;
	
	
	// Read values from stdin into array
	n = build_array(array);

	// Sort values in the array using selection sort
	quick_sort(array,0,n-1);

	// Print values in the array
	print_array(array, n);

	return 0;
}

int build_array(int array[]) {						// Builds array to use
	int n = 0;

	while (cin >> array[n]) {
		n++;
	}

	return n;
}


int partition(int array[], int start,int end) {				// function to do the sorting
	

	int mid = (start + end) / 2;					// declares and assigns int mid
	
	swap(array[start],array[mid]);					// swaps start and mid
	
	int pivot_index = start;					// declares and assigns pivot_index
	int pivot_value = array[start];					// declares and assigns pivot_value

	int scan = start + 1;						//delcares and assgins
	while(scan <= end) {						// runs while scan is less than or equal to end

		if (array[scan] < pivot_value) {			// runs if scan is less than pivot_value

			pivot_index = pivot_index +1;			// adds one to pivot_index
			swap (array[pivot_index],array[scan]);		// swaps values
		}
		scan = scan +1;						// adds 1 to scan
	}
	swap (array[start],array[pivot_index]);				//swaps the values
	return pivot_index;						// returns the value pivot_index

}

void quick_sort(int array[], int start, int end) {			// recursion function

	if(start < end) {						// runs if start is less than end base case

		int pivot_point = partition(array,start,end);		// calls partition
		quick_sort(array,start,pivot_point -1);			// sorts 
		quick_sort(array,pivot_point+1,end);			// sorts
	}

}


void print_array(int array[], int n) {					// prints values that were sorted
	int i;

	cout << right;

	for (i = 0; i < n; i++) {					// sets width to 8
		cout << setw(8) << array[i];

		if ((i+1) % 8 == 0)
			cout << endl;
	}

	// If last line is incomplete, print a newline.

	if (i % 8 != 0)
		cout << endl;
}
