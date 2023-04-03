/***************************************************************
CSCI 241         Assignment 12      spring 2021

Programmer: Trevor Berggren z1906236

Date Due: 04/22/2021
***************************************************************/

#ifndef SHAPE_H
#define SHAPE_H
        
#include <string>

class shape
{
    private:
    std::string color;

    public:
    shape() = default;
    shape(const std::string&);
    virtual ~shape();

    // Pure virtual function makes shape an abstract base class
    virtual double get_area()const = 0; // Pure virtual
    virtual void print()const;               // virtual
    

};
#endif