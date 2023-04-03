/***************************************************************
CSCI 241         Assignment 6      spring 2021

Programmer: Trevor Berggren z1906236

Date Due: 03/04/2021
***************************************************************/
#include <iostream>
#include <tuple>
#include "complex.h"
using namespace std;

    // Default constuctor
complex::complex(double r,double i){

    real = r;
    imaginary = i;

}
    
/********************************************************************************
 * returns the left hand side operator
 * @param lhs
 * @param rhs
 * this function take << and makes it able to print
 *
 ********************************************************************************/
 ostream& operator<<(ostream& lhs, const complex& rhs)
{
    lhs <<"("<< rhs.real<<", " << rhs.imaginary << ")";

    return lhs;
} 

/********************************************************************************
 * returns the right hand side operator
 * @param lhs
 * @param rhs
 * this function takes >> and makes it as user input
 *
 ********************************************************************************/
istream& operator>>(istream& lhs, complex& rhs){

    char unused;
    lhs >> rhs.real;
    lhs >> unused;
    lhs >> rhs.imaginary;
    return lhs;

        }
/********************************************************************************
 * returns the real number
 * no paramaters
 * const 
 * function just returns the real number
 * 
 ********************************************************************************/
double complex::get_real()const{

    return real;

        }
/********************************************************************************
 * returns the real imaginary number
 * no paramaters
 * const 
 * function just returns the imaginary number 
 *
 ********************************************************************************/
double complex::get_imaginary()const{

    return imaginary;

        }
/********************************************************************************
 * returns a tuple for real and imaginary numbers 
 * no paramaters
 * const 
 * function just returns the imaginary number and real number
 *
 ********************************************************************************/
tuple<double, double> complex::get_complex() const {
    
    return make_tuple(real,imaginary);

        }

/********************************************************************************
 * returns nothing
 * @param double r
 * function just assigns r to real
 *
 ********************************************************************************/
void complex::set_real(double r) {

    real = r;

        }

/********************************************************************************
 * returns nothing 
 * @param double i
 * function assigns i to imaginary
 *
 ********************************************************************************/
void complex::set_imaginary(double i){

    imaginary = i;
        }

/********************************************************************************
 * returns nothing
 * @param double r
 * @param double i 
 * function sets the complex numbers of real and imaginary
 *
 ********************************************************************************/
void complex::set_complex(double r,double i){

    real = r;
    imaginary = i;

        }

/********************************************************************************
 * returns a result as a double 
 * @param const COMPLEX rhs
 * const 
 * function is the operator plus 
 * add the real and real together vice verusa for imaginary
 *
 ********************************************************************************/
complex complex::operator+(const complex&rhs)const {

    complex result;

    result.real = real + rhs.real;
    result.imaginary = imaginary + rhs.imaginary;

    return result;

        }

/********************************************************************************
 * returns a result as a double 
 * @param const COMPLEX rhs
 * const 
 * mulitiply the real and real together vice verusa for imaginary
 * 
 ********************************************************************************/
complex complex::operator*(const complex&rhs)const{

    complex result;

    result.real = ( (real * rhs.real) -(imaginary*rhs.imaginary) );
    result.imaginary =( (real*rhs.imaginary) + (imaginary*rhs.real) ); 

    return result;


        }

/********************************************************************************
 * returns a bool
* @param const COMPLEX rhs
 * const 
 * function just returns a true if real equals real vice versa for imaginary
 *
 ********************************************************************************/
bool complex::operator==(const complex&rhs)const{

    if((real == rhs.real) && (imaginary == rhs.imaginary ) )
    return true;

    else
    return false;
        }