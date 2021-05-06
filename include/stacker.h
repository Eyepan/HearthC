#ifndef STACK_H
#define STACK_H

#include <tokens.h>
#define MAX_SIZE 128

typedef struct STACK_STRUCT
{
	int top;
	token_T st[1024];
} stack_T;


stack_T* initStack();
int push(stack_T* stack, token_T* token);
token_T* pop(stack_T* stack);
token_T* peek(stack_T* stack);
int isEmpty(stack_T stack);
void printStack(stack_T stack);

#endif // STACK_H