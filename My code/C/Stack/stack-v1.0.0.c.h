//filename: stack-v1.0.0.c.h
//author: PenG
//create time: 2019/02/15
//description: stack in c language for c program

#pragma once

#ifndef STACK_H_
#define STACK_H_

#include <stdlib.h>
#include <string.h>

/*
here is data area, you can edit it to fit your need.
*/
typedef struct StackData
{
	int data;//TODO
}StackData;

/*
here is stack information area, you ought not to change it.
*/
typedef struct StackInfo
{
	StackData *memoryHead;		//stack memory head record 栈内存空间的头记录

	unsigned int stackTop;		//it records the top offset of stack

	unsigned int sizeOfStack;	//amount of data that stack can store	这个就是表示这个栈可以存储多少个数据

	unsigned int sizeOfEmpty;	//size of empty space in stack 空余空间的大小
}StackInfo;

/*
	Initialize the stack info, it will request memory space.

	if stack equals to NULL then return -1
	if maxHeight equals to 0 then return -2
	if can not request the memory space then return -3
	success return 0
*/
int initStack(StackInfo *stack, unsigned int maxHeight);

/*
	push data to stack

	if stack equals to NULL then return -1
	if stack did not initialized then return -2
	if stack has no space to record the data then return -3
	success return 0
*/
int push(StackInfo *stack, StackData data);

/*
	pop data from stack top

	if stack equals to NULL then return -1
	if data equals to NULL then return -2
	if stack did not initialized then return -3
	if stack has no data then return -3
	success return 0
*/
int pop(StackInfo *stack, StackData *data);

/*
	if stack equals to NULL then return -1
	if stack did not initialized then return -3
	success return 0
*/
int releaseStack(StackInfo *stack);
#endif