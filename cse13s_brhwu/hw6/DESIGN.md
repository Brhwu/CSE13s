## Overview

HW6

search_util.c

written by Brandon Hwu

## Purpose

The purpose of the program is to have the student implement a solver for wordle.

## Layout

int score_letter

int score_word

size_t filter_vocabulary_gray

size_t filter_vocabulary_yellow

size_t filter_vocabulary_green

## Description

int score_letter

The function will loop over the vocabulary and return the number of words that contain the letter.

int score_word

The function will calculate the score for a given word with the score being how many unique letters are in the word.

size_t filter_vocabulary_gray

The function will filter the vocabulary to remove the words that contain a letter that is known to not be in the secret.

It will free the pointers and the spot of the filter words to NULL.

Returns the number of words that were filtered.

size_t filter_vocabulary_yellow

The function will filter the vocabulary to remove the words that contain a letter that is known to not be in the secret or contain the letter in the specific position.

It will free the pointers and the spot of the filter words to NULL.

Returns the number of words that were filtered.

size_t filter_vocabulary_green

The function will filter the vocabulary to remove the words that do not contain the letter in the specific position.

It will free the pointers and the spot of the filter words to NULL.

Returns the number of words that were filtered.

## Pseudocode

int score_letter(char letter, char vocabulary, size_t num_words)

   int num

   Loop through vocabulary using num_words

      if vocabulary word is NULL

         continue 

      if letter is in the vocabulary word

         add 1 to num

   return num


int score_word(char word, int letter_scores)

   int score

   loop through letter_scores

      make letter from letter_scores

      if letter is in word

         add letter_score value to score

   return score


size_t filter_vocabulary_gray(char letter, char vocabulary, size_t num_words)

   int num

   loop through vocabulary

      if vocabulary word is null

         continue

      if vocabulary word contains letter

            free vocabulary slot

            set slot equal to NULL

            add 1 to filter

return num


size_t filter_vocabulary_yellow(char letter, int position, char vocabulary, size_t num_words)

   int num

   loop through vocabulary

      if vocabulary word is null

         continue

      if vocabulary word does not contain letter or the vocabulary word position has letter

         free vocabulary slot

         set slot equal to NULL

         add 1 to filter

return num


size_t filter_vocabulary_green(char letter, int position, char vocabulary, size_t num_words)

   int num

   loop through vocabulary

      if vocabulary word is null

         continue

      if vocabulary word position does not contain letter

         free vocabulary slot

         set slot equal to NULL

         add 1 to filter

return num

