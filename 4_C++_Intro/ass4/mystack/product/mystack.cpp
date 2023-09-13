#include "mystack.h"

using namespace std;

int stackMeta::push(void* obj)
{
	/* create new object */
	StackObject_t *newObj = new StackObject_t;
	
	if(newObj != NULL){
		newObj->obj = operator new(objsize); //allocate memory for stored data
		memcpy(newObj->obj, obj, objsize); //copy data into memory of object
		newObj->next = stack; 
		stack = newObj; //new object added to top of stack
		numelem++;
		return 0;
	}
	else{ /* no space available */
		return-1;
	}
}

int stackMeta::pop(void* obj)
{
	/* temporary pointer to the top of the stack */
	StackObject_t *tempObj = stack;
	if(tempObj != NULL){
		memcpy(obj, tempObj->obj, objsize); //copy stored data into obj argument
		stack = tempObj->next; //next object becomes the top of stack
		operator delete (tempObj->obj);
		delete tempObj;
		numelem--;
		return 0;
	}
	else{ /* stack is empty */
		return -1;
	}
}


int stackMeta::nofelem()
{
	return numelem;
}    
