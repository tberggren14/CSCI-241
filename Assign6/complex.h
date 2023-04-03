/***************************************************************
CSCI 241         Assignment 6      spring 2021

Programmer: Trevor Berggren z1906236

Date Due: 03/04/2021
***************************************************************/

#ifndef COMPLEX_H
#define COMPLEX_H
#include <tuple>
using namespace std;

class complex 
{
    friend ostream& operator<<(ostream&, const complex&);
    friend istream& operator>>(istream&, complex&);

    private:
        double real;
        double imaginary;

    public:
        complex(double = 0.0, double = 0.0);
        double get_real()const;
        double get_imaginary()const; 
        std::tuple<double, double> get_complex() const;
        void set_real(double);
        void set_imaginary(double);
        void set_complex(double,double);
        complex operator+(const complex&)const;
        complex operator*(const complex&)const;
        bool operator==(const complex&)const;

};

#endif