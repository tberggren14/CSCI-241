/***************************************************************
CSCI 241         Assignment 8      spring 2021

Programmer: Trevor Berggren z1906236

Date Due: 03/18/2021
***************************************************************/

#include <string>
#include <sstream>
#include <cmath>
#include "inpost.h"
#include "eval.h"


using std::string;
using std::stringstream;

/********************************************************************************
 * returns int result
 * @param string postfix
 * function evluates the post fix and gives a value
 ********************************************************************************/
int evaluate(const string& postfix)
{
    string op;
    stringstream ss(postfix);     // Create a stringstream object from the postfix string.
    mystack eval_stack;


    // You can now read from the stringstream as if it were standard input. The end of the
    // string will be treated as the end of input.
    while (ss >> op)
    {
        if(islower(op[0])) {            // is a lowercase

            int result = op[0] - 'a';   // minus the letter
            eval_stack.push(result);    // pushes the result on the stack

        }

        else if(isdigit(op[0])){        // is a digit
            int result = stoi(op);      // converts string to int and assigns
            eval_stack.push(result);    // pushes the result on the stack


        }

        else if(op[0] == '~') {         // if operand is a ~
            int oper = eval_stack.top();    // gets the top of the stack
            eval_stack.pop();               // pops the stack
            int result = oper * -1;         // multiply operand by -1
            eval_stack.push(result);        // pushes the result on the stack

        }

        else {                              // this is a operator
            int result;                     // declares result varible 

            int right_oper = eval_stack.top();  // gets the top of the stack for left side
            eval_stack.pop();                   // pops the stack
            int left_oper =eval_stack.top();    // get the top of the stack for the right side
            eval_stack.pop();                   // pops the stack

            switch (op[0]){
                case '+':{                      // if operand is + adds the sides together
                 result = left_oper + right_oper;
                eval_stack.push(result);        // pushes the result on the stack
                break;
                }
                case '-':{                      // if operand is - subtracts the sides together
                 result = left_oper - right_oper;
                eval_stack.push(result);        // pushes the result on the stack
                break;
                }
                case '*':{
                 result = left_oper * right_oper;   // if operand is * multi the two sides 
                eval_stack.push(result);        // pushes the result on the stack
                break;
                }
                case '/':{
                if(left_oper == 0 || right_oper == 0) {     // checks to see if dividing by 0
                    cout << "*** Division by 0 ***" << endl;
                     return 0;
                    
                }
                 result = left_oper / right_oper;           // divides the two sides 
                eval_stack.push(result);        // pushes the result on the stack
                break;
                }
                case '^': {                             // if operand is ^ 
                    result =pow(left_oper,right_oper);  // pow does the exponent 
                    eval_stack.push(result);    // pushes the result on the stack
                }

        }
        
        }
        
    }

return eval_stack.top();                        // returns the top of the stack

}