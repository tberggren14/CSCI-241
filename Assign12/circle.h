/***************************************************************
CSCI 241         Assignment 12      spring 2021

Programmer: Trevor Berggren z1906236

Date Due: 04/22/2021
***************************************************************/

#ifndef CIRCLE_H
#define CIRCLE_H
        
#include "shape.h"
#include <string>
#include <math.h>

class circle : public shape
{
    private:
    int radius;
    double area;

    public:
    circle() = default;
    circle(const std::string&,int);

    // Pure virtual function makes shape an abstract base class
    virtual double get_area()const; // Pure virtual
    virtual void print()const;               // virtual


};
#endif