## Overview

HW5

hw5.c

written by Brandon Hwu

## Purpose

The purpose of the program is to have the student build a playable version of wordle.


## Layout

Functions

bool score_guess

bool valid_guess

char load_vocabulary

void free_vocabulary

main

## Description

bool score_guess

The function will return true of the player's guess is an exact match.

But if it is incorrect then it will fill the results with x, y, or g.

x means the letter in the guess does not appear in the word.

y means the letter in the guess is in the word but not in the right position.

g means the letter in the guess is in the word and in the right position.



bool valid_guess

The function will return true if the players guess is one of the strings in the vocabulary.

If it is not then it will return false.


char load_vocabulary

This function will return an array of strings where each string contains a word from a file.  

Also sets the value pointed at num_words to be the number of words read.


void free_vocabulary

This function frees the strings in the vocabulary and the pointer vocabulary.


## Pseudocode


bool score_guess(char secret, char guess, char result)

Establish variable win to check if word is exact match

For loop (i) to iterate through guess

   if guess letter in position i equals secret letter in position i

      copy into result 'g' in position i

      add to variable win

   else

      for loop (j) to iterate through rest of word in secret

         if guess letter in position i equals secret letter in position j

            copy into result 'y'

   if result letter in position i is not y and g

      copy into result 'x' in position i

   if win equals 5

      return true

   else

      return false



bool valid_guess(char guess, char vocabulary, size_t num_words)

   for loop (i) to iterate through num_words

      if string compare between the first 5 bytes in guess and vocabulary at position i

         return true

   return false


char load_vocabulary(char filename, size_t num_words)

   char out = NULL  (from the function)

   allocate space using calloc

   open file

   make num_words equal to 0

   establish size_t variable add

   establish char array temp

   while fgets is able to get bytes from filename

      duplicate string to out at position num_words from temp

      add 1 to num_words

      if num_words equals to size_t variable

         multiple add by 2

         allocate new memory using realloc to replace out with add multiplied to the size of char

         if new memory is not NULL

            replace out with new memory

         else

            break

   close file

   return out


void free_vocabulary(char vocabulary, size_t num_words)

   for loop (i) to iterate through num_words

      free element in vocabulary in position i

   free vocabulary

