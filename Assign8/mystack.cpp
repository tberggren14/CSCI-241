/***************************************************************
CSCI 241         Assignment 8      spring 2021

Programmer: Trevor Berggren z1906236

Date Due: 03/18/2021
***************************************************************/

#include "mystack.h"

/********************************************************************************
 * returns nothing
 * @param class object x
 * copy constructor
 *
 ********************************************************************************/
mystack::mystack(const mystack& x)
{
    // Set the new stack object's list to empty
    stack_top = nullptr;
    
    // Copy the other stack's size
    stack_size = x.stack_size;

    // Copy the other stack's linked list
    clone(x);
  
}

/********************************************************************************
 * returns nothing
 * no param
 * function deletes stack array
 ********************************************************************************/
mystack::~mystack()
{
    // deletes the stack array
    clear();

}

/********************************************************************************
 * returns this pointer
 * @param class object x
 * function is a overloaded copy assignment
 ********************************************************************************/
mystack& mystack::operator=(const mystack& x)
{
    if(this != &x){
        // Make the left stack object empty
        clear();
        
        // Copy the other stack's size
        stack_size = x.stack_size;

        // Copy the other stack's linked list
        clone(x);
    }
   
    return *this;
     
}


/********************************************************************************
 * returns stack_size
 * no param
 * function returns the stack size
 ********************************************************************************/
size_t mystack::size() const
{
    return stack_size;
    

}

/********************************************************************************
 * returns bool
 * no param
 * function returns true if size equals 0 overwise false
 ********************************************************************************/
bool mystack::empty() const
{
    if (stack_size == 0){
        return true;
    }
    return false;
     
}
/********************************************************************************
 * no return
 * no param
 * function clears stack size
 ********************************************************************************/
void mystack::clear()
{
    while(stack_size != 0){     // pops the stack to clear
        pop();                  
    }

}



/********************************************************************************
 * returns top of the stack
 * no param
 * function returns the top of the stack 
 ********************************************************************************/
const int& mystack::top() const
{
   
   return stack_top->value;
}

/********************************************************************************
 * mo return
 * @param value
 * function pushes the value to the back of the string
 ********************************************************************************/
void mystack::push(int value)
{
    // allocades a new node
    node* new_node = new node(value, stack_top);
    
    // assigns 
    stack_top = new_node;
    
    // adds to the stack size
    stack_size++;
     
}

/********************************************************************************
 * no return
 * no param
 * function pops the stack size by 1
 ********************************************************************************/
void mystack::pop()
{
    // allocades a new node

    node* delete_node = stack_top;

    // Assigns and then deletes
    stack_top = stack_top->next;
    delete[] delete_node;
    
    // minus from the size
    stack_size--;
}

/********************************************************************************
 * returns stack_size
 * @param mystack object
 * function clones the stack
 ********************************************************************************/
void mystack::clone(const mystack& x)
{
    // declares and assigns
    node* last = nullptr;
    node* ptr = x.stack_top;
    
    while(ptr != nullptr)
    {
        // allocades a new node
        node* new_node = new node(ptr->value);
        
        if (last == nullptr)
        {
            // assigns
            stack_top = new_node;
        }else
            last->next = new_node;
        
        // assigns
        last = new_node;
        ptr = ptr->next;
    }
}