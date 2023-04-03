/**
 * CSCI 241 Assignment 1
 *
 * Author: Treovr Berggren 
 * Z1906236
 *
 * insertion  sort
 *******************************************************/

#include <iostream>
#include <iomanip>


using namespace std;

 int  build_array(int[]);
 void print_array(int[], int);
 void insertion_sort(int[],int);

 int main()
	{
	 int array[1000];
    	 int count = 0;

	// Read the numbers into the array until the end

	count = build_array(array);

	// Calls the insertion sort function

	insertion_sort(array,count);


	 // Read the numbers into the array until the end

	print_array(array,count);

    return 0;


	}

	int  build_array(int array[])
	{
	int count = 0;

	 while (cin >> array[count])
	{

        	count++;
	}
	return count;
	}

	// Sorts the array by using insertion

	void insertion_sort(int array[],int n)
	{
    	int i,j;

    	i = 1;
    	while (i < n)
    	{
        j = i;

        while (j > 0 && array[j -1] > array[j])
        {
            swap (array[j-1],array[j]);
            j = j -1;
        }

        i = i + 1;
    	}
	 }


	// Prints the array in the form wanted

	void print_array(int array[], int count)
	{
	int i;

	for (i = 0; i < count; i++)
	{

        cout << setw(8) <<  array[i];
        if ((i+1) % 8==0 )
           cout << endl;

        }
        if (i % 8!= 0)
          cout <<  endl;
	}
