#ifndef __MYSTACK_H__
#define __MYSTACK_H__

#include <iostream>
#include <cstddef>
#include <cstring>

typedef struct stackObject
{
	void* obj;
	struct stackObject *next;
} StackObject_t;


class stackMeta
{
private:
	StackObject_t *stack; //pointer to first object of the stack
	size_t objsize;
	int numelem;
public:
    stackMeta(size_t osize){ //create my stack
		stack = NULL;
        objsize = osize;
        numelem = 0;
    }

    ~stackMeta(){ //destroy my stack
		StackObject_t *tempObj = stack;
		StackObject_t *nextObj = NULL; 
		while(tempObj != NULL){
			nextObj = tempObj->next;
			operator delete (tempObj->obj);
			delete tempObj;
			tempObj = nextObj;
		}
	}
    
    int push(void* obj);
    int pop(void* obj);
    int nofelem();
};


#endif

