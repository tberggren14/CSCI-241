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
void merge_sort(int[], int, int);
void print_array(int[], int);
void  merge(int[], int,int);

int main() {				// Driver code
	int array[1000];
	int n;
	
	
	// Read values from stdin into array
	n = build_array(array);

	// Sort values in the array using merge sort
	merge_sort(array,0,n-1);

	// Print values in the array
	print_array(array, n);

	return 0;
}

int build_array(int array[]) {			// Builds the array
	int n = 0;

	while (cin >> array[n]) {
		n++;
	}

	return n;
}


void  merge(int array[], int start, int mid, int end) {				// Sorts the values using merge algor

	int temp[end - start + 1];				// Temp value
	int i = start;						// Start of the array
	int j = mid +1;						// Middle of the array
	int k  = 0;						// Sets temp array to 0
	
	while(i <= mid && j <= end){				// While start is less than or equal to mis and mid is less than or equal to the end
		
		if(array[i] < array[j]){			// Runs if start is less than mid
		
		temp[k] = array[i];				// puts start in the temp array
		i = i +1;					// adds 1 to start
}
	else {							// Runs if the if statement is false 
		temp[k] = array[j];				// puts array j into the temp array
		j = j +1;					// adds one to j (the middle)
	}

	k = k + 1;						// adds one to the temp
	}
	while(i <= mid){					// runs while start is less than or equal to mid
		temp[k]= array[i];				// puts array i into temp
		i = i+ 1;					// adds one to start array
		k = k+1;					// adds one to temp array
	}
	while(j <= end){					// runs while mid array is less than or equal to end
		temp[k] = array[j];				// puts array j into temp
		j = j + 1;					// adds one to mid
		k = k + 1;					// adds one to temp array
	}
	
	for (i = start, j =0; i <= end; ++i,++j){		// runs while i is less than or equal to end
	
	array[i] = temp[j];					// makes array i(start) equal to array j(middle)
}
}

void merge_sort(int array[], int start, int end) {		// recursion function

if (start < end){						// base case
	
	int mid =(start +end) / 2;				// assigns and declares int mid
	merge_sort(array,start,mid);				// sorts
	merge_sort(array,mid + 1, end);				// calls to sort again
	merge(array,start,mid,end);				// calls to sort
	
}

}


void print_array(int array[], int n) { 				// prints the values 
	int i;

	cout << right;

	for (i = 0; i < n; i++) {
		cout << setw(8) << array[i];			// sets width to 8 

		if ((i+1) % 8 == 0)
			cout << endl;
	}

	// If last line is incomplete, print a newline.

	if (i % 8 != 0)
		cout << endl;
}
