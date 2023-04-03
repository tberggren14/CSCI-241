/**
 * CSCI 241 Assignment 1
 *
 * Author: Treovr Berggren 
 * Z1906236
 *
 * selction  sort
 *******************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

 int  build_array(int[]);
 void print_array(int[], int);
 void sort_array(int[],int);

 int main()
	{
	 int array[1000];
    	 int count = 0;

	// Read the numbers into the array until the end

	count = build_array(array);

	sort_array(array,count);


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

	void sort_array(int array[],int n)
	{
	int i, j, min_index;
	int temp;

	i = 0;
	while (i < n-1)
	{

	min_index = i;
	j = i +1;

	while (j <n)
	{
	if (array[j] < array[min_index])
	min_index = j;

	j = j + 1;
	}

	temp = array[i];
	array[i] = array[min_index];
	array[min_index] = temp;

	i = i + 1;
	}
     }

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
