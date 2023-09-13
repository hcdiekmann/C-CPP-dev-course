#ifndef __MYQUEUE_H__
#define __MYQUEUE_H__

#include <iostream>
#include "mystack.h"

class queueMeta
{
private:
	stackMeta *stack_in;
	stackMeta *stack_out;
public:
    queueMeta(int item_size){ //create my queue
		stack_in = new stackMeta(item_size);
		stack_out = new stackMeta(item_size);
    }

    ~queueMeta(){ //destroy my queue
		delete stack_in;
		delete stack_out;
	}
    
    int enqueue(void *obj);
    int dequeue(void *obj);
};


#endif

