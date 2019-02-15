//filename: stack-v1.0.0.c
//author: PenG
//create time: 2019/02/15
//description: stack in c language for c program

#include "stack-v1.0.0.c.h"

int initStack(StackInfo *stack, unsigned int maxHeight)
{
	if (NULL == stack)
	{
		return -1;
	}

	stack->sizeOfStack = 0;

	if (0 == maxHeight)
	{
		return -2;
	}

	if ((stack->memoryHead = (StackData *)malloc(sizeof(StackData)*maxHeight)) == NULL)
	{
		return -3;
	}

	stack->sizeOfEmpty = maxHeight;
	stack->sizeOfStack = maxHeight;
	stack->stackTop = 0;

	return 0;
}

int push(StackInfo *stack, StackData data)
{
	if (NULL == stack)
	{
		return -1;
	}

	if (0 == stack->sizeOfStack)
	{
		return -2;
	}

	if (0 == stack->sizeOfEmpty)
	{
		return -3;
	}

	memcpy(&stack->memoryHead[stack->stackTop + 1], &data, sizeof(StackData));

	stack->sizeOfEmpty--;
	stack->stackTop++;

	return 0;
}

int pop(StackInfo *stack, StackData *data)
{
	if (NULL == stack)
	{
		return -1;
	}

	if (NULL == data)
	{
		return -2;
	}

	if (0 == stack->sizeOfStack)
	{
		return -3;
	}

	if (0 == stack->stackTop)
	{
		return -4;
	}

	memcpy(data, &stack->memoryHead[stack->stackTop], sizeof(StackData));

	stack->sizeOfEmpty++;
	stack->stackTop--;

	return 0;
}

int releaseStack(StackInfo *stack)
{
	if (NULL == stack)
	{
		return -1;
	}

	if (0 == stack->sizeOfStack)
	{
		return -2;
	}

	free(stack->memoryHead);

	stack->memoryHead = NULL;

	stack->sizeOfEmpty = 0;
	stack->sizeOfStack = 0;
	stack->stackTop = 0;

	return 0;
}