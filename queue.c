/*
Implimentation of Queue in C.
This program contains array based implementation of a queue 
in C program. Following functions has been implimented.
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

struct QueueNode
{
	int queueData[MAX_QUEUE_SIZE];
	int tail,head;
};

struct QueueNode* createQueue()
{
	struct QueueNode* queue= (struct QueueNode*) malloc(sizeof(struct QueueNode));
	queue->tail =0;
	queue->head = 0;
	return queue;
}

void enqueue(struct QueueNode* queue,int data)
{
	
	queue->queueData[queue->head] = data;
	queue->head = queue->head + 1;
	if(queue->head >=MAX_QUEUE_SIZE)
		queue->head=0;

}

int dequeue(struct QueueNode* queue)
{
	int data;

	if(queue->tail >= queue->head)
	{
		queue->tail=queue->head=0;
		printf("Queue is empty.\n");
	}
	data = queue->queueData[queue->tail];
	queue->tail++;
	
	
	if(queue->tail >=MAX_QUEUE_SIZE)
		queue->tail=0;
}

int getFirst(struct QueueNode* queue)
{
	if (queue->head == queue->tail)
	{
		printf("Queue is empty.\n");
		return;
	}
	return queue->queueData[queue->tail];
}


void main ()
{
	struct QueueNode* queue;
	queue = createQueue();
	getFirst(queue);
	enqueue(queue,10);
	printf("%d \n",getFirst(queue));
	enqueue(queue,101);
	dequeue(queue);
	dequeue(queue);
	printf("%d \n",getFirst(queue));
	enqueue(queue,102);
	printf("%d \n",getFirst(queue));


}