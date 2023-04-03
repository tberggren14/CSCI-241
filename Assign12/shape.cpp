/***************************************************************
CSCI 241         Assignment 12      spring 2021

Programmer: Trevor Berggren z1906236

Date Due: 04/22/2021
***************************************************************/

#include <iostream>
#include "shape.h"

using namespace std;

// constructor for base 
shape::shape(const string& color)
{
    this->color = color;

}

// deconstructor
shape::~shape()
{
}

// Prints the color
void shape::print()const
{
    cout << color << " ";

}