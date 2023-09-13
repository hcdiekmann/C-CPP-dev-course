#include "myqueue.h"

using namespace std;

int queueMeta::enqueue(void *obj)
{
	return stack_in->push(obj);
}

int queueMeta::dequeue(void *obj)
{
	if(stack_out->nofelem() == 0){ //stack_out is empty
		while(stack_in->nofelem() > 0){ //move elements from stack_in to stack_out
			stack_in->pop(obj);
			stack_out->push(obj);
		}
	}
	return stack_out->pop(obj);
}




