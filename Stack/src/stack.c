/*
 * stack.c
 *
 *  Created on: Dec 25, 2019
 *      Author: Tanmay
 */
#include "stack.h"

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


