/*
 * stack.h
 *
 *  Created on: Dec 25, 2019
 *      Author: Tanmay
 */

#ifndef STACK_H_
#define STACK_H_
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


#endif /* STACK_H_ */
