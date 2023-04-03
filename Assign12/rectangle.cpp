/***************************************************************
CSCI 241         Assignment 12      spring 2021

Programmer: Trevor Berggren z1906236

Date Due: 04/22/2021
***************************************************************/

#include <iostream>
#include "rectangle.h"


using namespace std;

/**
 * Constructor for rectangle shape.
 *
 * @param color for shape color
 * @param height fr height
 * @param width for width
 *
 ********************************************************************/
rectangle::rectangle(const string& color, int height, int width) : shape(color), height(height), width(width)
{
    this->height = height;
    this->width = width;        // sets height and width and calls area to assing
    area = get_area();

}

/**
 * Accessor function
 *
 * @return area.
 ********************************************************************/
double rectangle::get_area()const
{
    double area = height * width;
    return area;                    // calcs area and returns it
}

/**
 * Prints information
 ********************************************************************/
void rectangle::print()const
{
    shape::print();     // call shape version of print

    // prints remaining information
    cout << "rectangle, " << "height " << height << ", ";
    cout <<"width " << width << ", " << "area " << area << endl;

}