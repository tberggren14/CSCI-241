/***************************************************************
CSCI 241         Assignment 12      spring 2021

Programmer: Trevor Berggren z1906236

Date Due: 04/22/2021
***************************************************************/

#ifndef TRIANGLE_H
#define TRIANGLE_H
        
#include "shape.h"
#include <string>

class triangle: public shape
{
    private:
    int height = 0;
    int base = 0;
    double area;

    public:
    triangle() = default;
    triangle(const std::string&,int,int);

    // Pure virtual function makes shape an abstract base class
    virtual double get_area()const; // Pure virtual
    virtual void print()const;               // virtual

};
#endif