#include "review.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Functions for you to implement. Most of the work for this homework will be
// done in here, but you'll also need to make changes to review.h and yelling.c.

// Problem 1
void sum_and_difference(int a, int b, int *sum, int *difference) {
  //  Your code goes here!
  int added = a;
  added = added + b;
  *sum = added;

  int sub = a;
  sub = sub - b;
  *difference = sub;
}


// Problem 2


// This one ought to be recursive.
size_t ll_length(LLint *node) {
  // change this, clearly.
  if (node == NULL) {
      return 0;
  }
  else {
      return 1 + ll_length(node->next);
  }
}

// Do this one iteratively.
size_t ll_length_iterative(LLint *node) {
  // These are just default return values; they're for you to change.
  size_t i = 0;
  LLint *current = node;
  while (current != NULL) {
      i++;
      current = current->next;
  }
  return i;
}


// Problem 3.

//helper function for stack
void push(Stack *s, double data) {
  Stack *newtop = (Stack *)calloc(1, sizeof(Stack));

  newtop->data = data;
  newtop->next = s->top;
  s->top = newtop;
}

//helper function for stack
double pop(Stack *s, double *item) {

  double result = s->top->data;
  *item = result;
  Stack *delete_this = s->top;
  s->top = s->top->next;

  free(delete_this);
  return result;
}


void stack_delete(Stack **s) {
  // your code here
  while((*s)->top != NULL) {
	free((*s)->top);
  }
  free(*s);
  s = NULL;
}



void reverse_doubles_with_stack(double *array, size_t array_len) {
  // This function will reverse the order of the array pointed to by *array.
  // Make sure to define your linked list data structure in review.h, and use
  // stack behavior (LIFO) to get the numbers in the reversed order.
  // There is a way to do this without a stack data structure, I know. But this
  // is for practice with data structures.
   
    Stack *stack = (Stack *)calloc(array_len, sizeof(Stack));
  
    for (size_t i = 0; i < array_len; i++) {
        push(stack, array[i]);
    }
  
    for (size_t i = 0; i < array_len; i++) {
        array[i] = pop(stack, &array[i]);
    }
  
    // for testing the output
    //for (size_t i = 0; i < array_len; i++) {
        //printf("%f ", array[i]);

stack_delete(&stack);
}

// Problem 4.

tnode *word_observe(char *word, tnode *node) {
  // This function returns a pointer to a tnode because you may have to allocate
  // a new one. You might take a NULL pointer to start with.
  // Also, this means that you can very cleanly do this with recursion.
  if (node == NULL) {
	  tnode *out = calloc(1, sizeof(tnode));
     
	  out->word = strdup(word);
	  out->count = 1;
	  out->left = NULL;
	  out->right = NULL;

  return out;
  }

  int strcompare = strcmp(word, node->word);
  if(strcompare == 0) {
	  node->count +=1;
  }

  else if (strcompare < 0) {
	  node->left = word_observe(word, node->left);
  }
  else {
	  node->right = word_observe(word, node->right);
  }
  return node;
}

int word_count(char *word, tnode *node) {
  // Default return values; here for you to change.
  if (node == NULL) {
  return 0;
  }

  int strcompare = strcmp(word, node->word);
  if(strcompare == 0) {
	  return node->count;
  }
  else if (strcompare < 0) {
	  return word_count(word, node->left);
  }
  else {
	  return word_count(word, node->right);
  }
  return 0;
}

void delete_tree(tnode *node) {
  // Free the whole tree and all associated memory. This can be recursive or
  // not, your choice!
  if (node != NULL) {
	  delete_tree(node->left);
	  free(node->word);
	  delete_tree(node->right);
	  free(node);
}
}
