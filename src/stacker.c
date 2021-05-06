#include <stacker.h>

stack_T* initStack()
{
	stack_T* stack = calloc(1, sizeof(struct STACK_STRUCT));
	stack->top = -1;
	return stack;
}

int push(stack_T* stack, token_T* token)
{
	if (stack->top >= (MAX_SIZE - 1))
	{
		printf("\n\tERR: STACK_OVERFLOW\n");
		return 0;
	}
	stack->st[++stack->top] = *token;
	return 1;
}

token_T* pop(stack_T* stack)
{
	if (stack->top < 0)
	{
		printf("\n\tERR: STACK_UNDERFLOW\n");
		return initToken(TT_EOF, "\n");
	}
	return &stack->st[stack->top--];
}

token_T* peek(stack_T* stack)
{
	if (stack->top < 0)
	{
		return initToken(TT_EOF, "\n");
	}
	return &stack->st[stack->top];
}

int isEmpty(stack_T stack)
{
	return (stack.top < 0);
}

void printStack(stack_T stack)
{
	while (!isEmpty(stack))
	{
		printToken(pop(&stack));
	}	
}