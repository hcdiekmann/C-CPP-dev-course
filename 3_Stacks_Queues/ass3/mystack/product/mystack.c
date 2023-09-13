
#include "mystack.h"
#include "logging.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
/* The stack is an abstract data type.
* this means that the internal structures are
* never exposed to the users of the library.
*/

/* Note: the stacks have no knowledge of what types
* they are storing. This is not a concern of the stack
*/

StackMeta_t *mystack_create(size_t objsize)
{
	StackMeta_t *newstack = malloc(sizeof(StackMeta_t));
	if(newstack != NULL && objsize > 0){
		newstack->stack = NULL;
		newstack->objsize = objsize;
		newstack->numelem = 0;
		return newstack;
	}
	else{
		return NULL;
	}
}

int mystack_push(StackMeta_t *stack, void* obj)
{
	/* pointer to new object */
	StackObject_t *newObj = malloc(sizeof(StackObject_t));
	newObj->obj = malloc(stack->objsize); //allocate memory for stored data
	
	if(newObj != NULL){
		memcpy(newObj->obj, obj, stack->objsize); //copy data into memory of object
		newObj->next = stack->stack; 
		stack->stack = newObj; //new object added to top of stack
		stack->numelem++;
		return 0;
	}
	else{ /* no space available */
		return-1;
	}
	
}

int mystack_pop(StackMeta_t *stack, void* obj)
{
	/* temporary pointer to the top of the stack */
	StackObject_t *tempObj = stack->stack;
	if(tempObj != NULL){
		memcpy(obj, tempObj->obj, stack->objsize); //copy stored data into obj argument
		stack->stack = tempObj->next; //next object becomes the top of stack
		free(tempObj->obj);
		free(tempObj);
		stack->numelem--;
		return 0;
	}
	else{ /* stack is empty */
		return -1;
	}
}

void mystack_destroy(StackMeta_t *stack)
{
	/* temporary pointer to the top of the stack */
	StackObject_t *tempObj = stack->stack;
	StackObject_t *nextObj = NULL; 
	while(tempObj != NULL){
		nextObj = tempObj->next;
		free(tempObj->obj);
		free(tempObj);
		tempObj = nextObj;
	}
	free(stack);
}

int mystack_nofelem(StackMeta_t *stack)
{
	if(stack != NULL){
		return stack->numelem;
	}
	return -1;
}
