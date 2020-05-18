/*
 ============================================================================
 Name        : Stack.c
 Author      : Tanmay
 Version     :
 Copyright   : Avengers Assemble
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "stack.h"

int main(void)
{
	stack_t *top=(stack_t*) malloc(sizeof(stack_t));
	top->size=0;
	top->next=NULL;
	assert(push(top,5));
	assert(push(top,6));
	assert(push(top,7));
	printStack(top);
	pop(top);
	printStack(top);
	isEmpty(top) ? printf("Stack not empty") : printf("Stack empty");
	return 0;
}
