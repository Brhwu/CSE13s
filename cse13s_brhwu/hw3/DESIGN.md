## Overview

HW3

stack_calculator.c

written by Brandon Hwu

## Purpose

The purpose of the program is to have the student implement a stack-based calculator which is essentually a tiny programming language.

It will have the student apply what they have learned about some of the data structures, particularly linked lists and stacks.

## Layout

Functions

Stack stack_create(finished already)

bool stack_push

bool stack_pop

bool stack_empty

void stack_delete

bool stack_compute_step


## Description


bool stack_push

Will add a new node at the front of stack.  Return false if it is not possible.
Code is based on class demo file stack.c


bool stack_pop

Will pop the stack and put the results into the output printer.  Return false if stack is NULL or empty.
Code is based on class demo file stack.c


bool stack_empty

Will return true if the specified stack is empty


void stack_delete

Will free all of the memory used by the stack along with its linked list.  Will set pointer to NULL when done.


bool stack_compute_step

Will return true if the computation step was successful and returns false if there is an error.


## Pseudocode


bool stack_push

code is based on class demo stack.c

Prepare node

if node is NULL 

    return false

stick node on front of stack


bool stack_pop

check if stack is NULL or empty

    return false

place result in output printer

pop the stack

return true


bool stack_empty

code is based on class demo file stack.c

if top of stack is NULL 
       
        return false
else 

Return true


void stack_delete

while top of stack is not NULL

    pop stack 

free pointer

set array to NULL

return true


bool stack_compute_step

if item is a number 

   push onto stack

   return true

establish CalculatorItem item1

establish CalculatorItem item 2

establish pop1 stack with item 1

establish pop2 stack with item 2

if pop1 does not equal pop2 or pop1 equals 0

   return false

establish CalculatorItem result

if item is a plus

   result = item1 + item2

   push result

if item is a minus

   result = item1 + item2

   push result

if item is an asterisk

   result = item2 * item1

   push result

if item is a slash
   
   if item1 equals 0
 
      return false

   result = item2 / item1

   push result


return true






