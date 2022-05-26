## Overview

HW2

num_arrays.c

written by Brandon Hwu


## Purpose

The purpose of the program is to make functions that deal array of integers.  It will have the students think about pointers that adress into arrays and pointers to functions.


## Layout

Functions

hf_max(int x, int y)

hf_sum(int x, int y)

hf_negative_count(int x. int y)

maximum(int nums, int len)

sum_positive(int nums, int len)

reduce(int nums, int len, int (f)(int,int), int initial)

maximum_with_reduce(int nums, int size)

sum_positive_with_reduce(int nums, int size)

count_negative_with_reduce(int nums, int size)


## Description


hf_max(int x, int y)

This is a helper function for function maximum_with_reduce.



hf_sum(int x, int y)

This is a helper function for function sum_positive_with_reduce.



hf_negative_count(int x. int y)

This is a helper function for function count_negative_with_reduce.



maximum(int nums, int len)

This function gets the maximum element of an array.



sumpositive(int nums, int len)

This function returns the sum of all elements in an array that are positive.



reduce(int nums, int len, int (f)(int,int), int initial)

This function combines all the elements in an array with a specified function.

It will maintain a current cumulative value.

The specified function will be applied to the cumulative value and every element in the array.

This will produce a new accumulator.



maximumwithreduce(int nums, int size)

This function calls on reduce and returns the maximum element in the array.

Has a helper function.



sumpositivewithreduce(int nums, int size)

This function calls on reduce and returns the sum of all positive numbers in the array.

Has a helper function.



countnegativewithreduce(int nums, int size)

This function calls on reduce and returns the count of negative numbers in the array.

Has a helper function.



## Pseudocode


hf_max(int x, int y)
    
    checks if x or y is bigger than each other

        returns the bigger variable



hf_sum(int x, int y)

    check if y is greater than 0 (not negative)

        if so add y to x and return x

    else 

        return x



hf_negative_count

    check if y is less than 0

        if so add 1 to x and return

    else
  
        return x



maximum(number array, length of array)

    make int variable "max" equal to first element of array

    loop through all elements in the array 

        int variable "check" to save array element

        if array element > max 

            set max equal to array element

    return max



sum_positive(number array, length of array)

    make int variable "sum"

    loop through all elements in the array 

        int variable "check" to save array element

        if array element > 0

            add array element to sum

    return sum



reduce(number array, length of array, int(f)(int, int), initial)

    loop through all elements in the array

        set initial equal to f with initial and array element as its first and second elements respectively.

    return initial



maximum_with_reduce(number array, int size)

    make int variable "value" equal to reduce(number array, size, helper function, first element of array)

    return value



sum_positive_with_reduce(number array, int size)

    make int variable "value" equal to reduce(number array, size, helper function, initial value of 0)

    return value



count_negative_with_reduce(number array, int size)

    make int variable "value" equal to reduce(number array, size, helper function, initial value of 0)

    return value





                     
