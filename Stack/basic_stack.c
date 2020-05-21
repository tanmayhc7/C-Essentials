/*
 * stack.c
 *
 *  Created on: Dec 25, 2019
 *      Author: Tanmay
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#define CAPACITY 10
typedef struct stack
{
	uint16_t val;
	uint8_t size;
	struct stack *next;
}stack_t;

bool push(stack_t *top,uint16_t val);
void pop(stack_t *top);
bool isEmpty(stack_t *top);
void printStack(stack_t *top);

bool push(stack_t *top,uint16_t val)
{
	if(top->size>=CAPACITY)
	{
		printf("Buffer Overflow\n");
		return 0;
	}
	stack_t *newNode=(stack_t*) malloc(sizeof(stack_t));
	newNode->val=val;
	newNode->next=top->next;

	top->next=newNode;
	top->size+=1;
	return 1;
}

void pop(stack_t *top)
{
	stack_t *temp=top->next;
	top->next=temp->next;
	printf("Pop: %d\n",temp->val);
	free(temp);
}

void printStack(stack_t *top)
{
	stack_t *temp=top->next;
	while(temp)
	{
		printf("%d\t",temp->val);
		temp=temp->next;
	}
	printf("\n");
}

bool isEmpty(stack_t *top)
{
	return (top->size)?1:0;
}

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


