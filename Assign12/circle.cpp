/***************************************************************
CSCI 241         Assignment 12      spring 2021

Programmer: Trevor Berggren z1906236

Date Due: 04/22/2021
***************************************************************/

#include <iostream>
#include "circle.h"


using namespace std;

/**
 * Constructor for circle shape.
 *
 * @param color for shape color
 * @param radius for radius
 *
 ********************************************************************/
circle::circle(const string& color, int radius) : shape(color), radius(radius)
{
    this->radius = radius;
    area = get_area(); // sets radius and assigns area

}

/**
 * Accessor function
 *
 * @return area.
 ********************************************************************/
double circle::get_area()const
{
    double area = M_PI * radius * radius;
    return area;            // calcs area and returns
}

/**
 * Prints information
 ********************************************************************/
void circle::print()const
{
    shape::print();     // call shape version of print

    // prints remaining information
    cout << "circle, " << "radius " << radius << ", ";
    cout << "area " << area << endl;

}