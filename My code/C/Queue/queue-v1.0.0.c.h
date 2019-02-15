//filename: queue-v1.0.0.c.h
//author: PenG
//create time: 2019/02/15
//discription: queue in c language for c program

#pragma once
#ifndef QUEUE_C_H_
#define QUEUE_C_H_

#include <stdlib.h>
#include <string.h>

/*
	here is data area, you can edit it to fit your need.
*/
typedef struct QueueData
{
	int data;//TODO
}QueueData;

/*
	here is queue information area, you ought not to change it.
*/
typedef struct QueueInfo
{
	QueueData *memoryHead;		//queue memory head record �����ڴ�ռ��ͷ��¼
	
	unsigned int queueHead;		//queue head, different from memoryHead, it records the start offset of queue
	unsigned int queueTail;		//it records the tail offset of queue

	unsigned int sizeOfQueue;	//amount of data that queue can store	������Ǳ�ʾ������п��Դ洢���ٸ�����

	unsigned int queueLength;	//length of queue used
	unsigned int sizeOfEmpty;	//size of empty space in queue ����ռ�Ĵ�С
}QueueInfo;

/*
	Initialize the queue info, it will request memory space.

	if queue equals to NULL then return -1
	if maxLength equals to 0 then return -2
	if can not request the memory space then return -3
	success return 0
*/
int initQueue(QueueInfo *queue, unsigned int maxLength);

/*
	record data to queue

	if queue equals to NULL then return -1
	if queue did not initialized then return -2
	if queue has no space to record the data then return -3
	success return 0
*/
int inQueue(QueueInfo *queue, QueueData data);

/*
	get data from queue

	if queue equals to NULL then return -1
	if data equals to NULL then return -2
	if queue did not initialized then return -3
	if queue has no data then return -3
	success return 0
*/
int outQueue(QueueInfo *queue, QueueData *data);

/*
	release the memory of queue

	if queue equals to NULL then return -1
	if queue did not initialized then return -3
	success return 0
*/
int releaseQueue(QueueInfo *queue);

#endif