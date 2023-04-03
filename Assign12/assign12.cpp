/***************************************************************
CSCI 241         Assignment 12      spring 2021

Programmer: Trevor Berggren z1906236

Date Due: 04/22/2021
***************************************************************/
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
    
    // create vector shapes
    vector<shape*> shapes;

     // initialize vector with shape information
    shapes.push_back(new circle("green", 10 ));
    shapes.push_back(new rectangle("red", 8, 6 ));
    shapes.push_back(new triangle("yellow", 8, 4 ));

    shapes.push_back(new triangle("black", 4, 10 ));
    shapes.push_back(new circle("orange", 5 ));
    shapes.push_back(new rectangle("blue", 3, 7 ));

    cout << "Printing all shapes...\n\n";

    // generically process each element in vector shapes
    for(size_t i = 0; i < shapes.size(); i++)
    {
        // output shape information
        shapes[i]->print();
    }

    cout << "\nPrinting only circles...\n\n";

    // test for only circles 
    for(size_t i = 0; i < shapes.size(); i++)
    {
        // attempt to downcast a pointer
        circle* p = dynamic_cast<circle*>(shapes[i]);

        if(p != nullptr)
        {   
                // prints only the circles
                shapes[i]->print();
        }
    }
     // Release memory held by vector shapes
    for(size_t i = 0; i < shapes.size(); i++)
    {
        delete shapes[i];
    }
}