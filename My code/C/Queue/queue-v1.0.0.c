//filename: queue-v1.0.0.c
//author: PenG
//create time: 2019/02/15
//description: queue in c language for c program

#include "queue-v1.0.0.c.h"

int initQueue(QueueInfo *queue, unsigned int maxLength)
{
	if (NULL == queue)
	{
		return -1;
	}

	queue->sizeOfQueue = 0;

	if (0 == maxLength)
	{
		return -2;
	}

	if ((queue->memoryHead = (QueueData *)malloc(sizeof(QueueData) * maxLength)) == NULL)
	{
		return -3;
	}

	queue->queueHead = 0;
	queue->queueTail = 0;

	queue->sizeOfQueue = maxLength;

	queue->queueLength = 0;
	queue->sizeOfEmpty = maxLength;

	return 0;
}

int inQueue(QueueInfo *queue, QueueData data)
{
	if (NULL == queue)
	{
		return -1;
	}

	if (0 == queue->sizeOfQueue)
	{
		return -2;
	}

	if (0 == queue->sizeOfEmpty)
	{
		return -3;
	}

	memcpy(&queue->memoryHead[queue->queueTail], &data, sizeof(QueueData));

	if (queue->queueTail == (queue->sizeOfQueue - 1))
	{
		queue->queueTail = 0;
	}
	else
	{
		queue->queueTail++;
	}

	queue->queueLength++;
	queue->sizeOfEmpty--;

	return 0;
}

int outQueue(QueueInfo *queue, QueueData *data)
{
	if (NULL == queue)
	{
		return -1;
	}

	if (NULL == data)
	{
		return -2;
	}

	if (0 == queue->sizeOfQueue)
	{
		return -3;
	}

	if (0 == queue->queueLength)
	{
		return -4;
	}

	memcpy(data, &queue->memoryHead[queue->queueHead], sizeof(QueueData));

	if (queue->queueHead == (queue->sizeOfQueue - 1))
	{
		queue->queueHead = 0;
	}
	else
	{
		queue->queueHead++;
	}

	queue->queueLength--;
	queue->sizeOfEmpty++;

	return 0;
}

int releaseQueue(QueueInfo *queue)
{
	if (NULL == queue)
	{
		return -1;
	}

	if (0 == queue->sizeOfQueue)
	{
		return -2;
	}

	free(queue->memoryHead);

	queue->queueHead = 0;
	queue->queueTail = 0;
	
	queue->queueLength = 0;
	queue->sizeOfEmpty = 0;

	queue->sizeOfQueue = 0;

	return 0;
}
