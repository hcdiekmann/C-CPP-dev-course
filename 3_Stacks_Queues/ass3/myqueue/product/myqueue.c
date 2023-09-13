#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>

#include "mystack.h"
#include "myqueue.h"

QueueMeta_t *myqueue_create(int item_size)
{
	QueueMeta_t *newqueue = malloc(sizeof(QueueMeta_t));
	if(newqueue != NULL && item_size > 0){
		newqueue->stack_in = mystack_create(item_size);;
		newqueue->stack_out = mystack_create(item_size);;
		return newqueue;
	}
	else{
		return NULL;
	}
}

void myqueue_delete(QueueMeta_t *queue)
{
	mystack_destroy(queue->stack_in);
	mystack_destroy(queue->stack_out);
	free(queue);
	return;
}

int myqueue_enqueue(QueueMeta_t *que, void *obj)
{
	return mystack_push(que->stack_in, obj);
}

int myqueue_dequeue(QueueMeta_t *queue, void *obj)
{
	if(queue->stack_out->numelem == 0){ //stack_out is empty
		while(queue->stack_in->numelem > 0){ //move elements from stack_in to stack_out
			mystack_pop(queue->stack_in, obj);
			mystack_push(queue->stack_out, obj);
		}
	}
	return mystack_pop(queue->stack_out, obj);
}




