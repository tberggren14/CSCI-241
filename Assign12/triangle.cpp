/***************************************************************
CSCI 241         Assignment 12      spring 2021

Programmer: Trevor Berggren z1906236

Date Due: 04/22/2021
***************************************************************/

#include <iostream>
#include "triangle.h"


using namespace std;

/**
 * Constructor for triangle shape.
 *
 * @param color for shape color
 * @param height fr height
 * @param base for base
 *
 ********************************************************************/
triangle::triangle(const string& color, int height, int base) : shape(color), height(height), base(base)
{
    this->height = height;
    this->base = base;              // assigns and calls area
    area = get_area();

}

/**
 * Accessor function
 *
 * @return area.
 ********************************************************************/
double triangle::get_area()const
{
    double area = 0.5 * height * base;
    return area;                    // calcs area and returns it
}

/**
 * Prints information
 ********************************************************************/
void triangle::print()const
{
    shape::print();// call shape version of print

    // prints remaining information
    cout << "triangle, " << "height " << height << ", ";
    cout <<"base " << base << ", " << "area " << area << endl;

}