#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack_calculator.h"

// Allocate a new Stack struct and return a pointer to it.
Stack *stack_create(void) {
  // this one is complete, no need to change it!
  Stack *out;
  out = (Stack *)calloc(1, sizeof(Stack));
  return out;
}

// Add a new node at the front of the stack. Return false if we are unable to do
// so (eg, if memory allocation fails).
bool stack_push(Stack *s, CalculatorItem item) {
  // your code here
  // code based on class demo file stack.c
  Node *newtop = (Node *)calloc(1, sizeof(Node));
  if (newtop == NULL) {
	return false;
  }

  newtop->item = item;
  newtop->next = s->top;

  s->top = newtop;
  return true;
}

// Pop the stack and put the result into the output pointer.
// return false if the stack is NULL or if it is empty.
bool stack_pop(Stack *s, CalculatorItem *output) {
  // your code here
  // code based on class demo file stack.c
  if (s == NULL || s->top == NULL) {
	return false;
  }

  CalculatorItem result = s->top->item;
  *output = result;

  Node *delete_this = s->top;
  s->top = s->top->next;

  free(delete_this);
  return true;
}

// Returns true if the specified stack is empty.
bool stack_empty(Stack *s) {
  // your code here
  if(s->top == NULL) {
	return true;
  }
  else {
	return false;
  }
}

// Free all of the memory used by this stack, including its linked list.
// When you are done, set the pointer to NULL.
void stack_delete(Stack **s) {
  // your code here
  while((*s)->top != NULL) {
	Node *delete_this = (*s)->top;
	(*s)->top = (*s)->top->next;
	free(delete_this);
  }
  free(*s);
  s = NULL;
}

// Returns true if we were able to successfully perform the computation step,
// and false if there was an error of some kind.
bool stack_compute_step(Stack *s, CalculatorItem item) {
// your code here
  if(item.type == NUMBER) {
        stack_push(s, item);
	return true;
}

  CalculatorItem item1;
  CalculatorItem item2;

 bool pop1 = stack_pop(s, &item1);
 bool pop2 = stack_pop(s, &item2);
 if(pop1 != pop2 || pop1 == 0) {
	 return false;
 }
  CalculatorItem result;
  if(item.type == ADD) {
	result.value =(item1.value + item2.value);
	stack_push(s, result);
  }
  if(item.type == SUBTRACT) {
	result.value = item2.value - item1.value;
	stack_push(s, result);
  }
  if(item.type == MULTIPLY) {
	result.value = item2.value * item1.value;
	stack_push(s, result);
  }
  if(item.type == DIVIDE) {
	if(item1.value == 0) {
		return false;
	}
	result.value = item2.value / item1.value;
	stack_push(s, result);
  }
return true;
}




