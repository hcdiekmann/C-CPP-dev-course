
#include "mem_functions.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


void showList (ELEMENT * list)
/* pre : list = NULL or a linear linked list of ELEMENT structures; the next pointer of the last element is NULL
 * post: All data of the list are printed on the screen
 */
{
    if (list == NULL)
    {
        printf ("  <empty>\n");
        return;
    }
    
    int i = 0;
    ELEMENT *el = list;
	while(el != NULL)
	{
		printf ("%3d:  addr:%4d  size:%4d\n", i, el->addr, el->size);
		i++;
		el = el->next;
	}
	free(el);
} /* showList */


int freeMemory (ELEMENT ** freeList, ELEMENT ** allocList, int addr)
/* pre:  Parameter addr must match the start of an allocatd memory block. Otherwhise return -1.
 *
 * post: If addr is a part of allocated memory of allocList then the memory from this address
 * 	     with registered nrofBytes should be removed from the *allocList and added to the *freeList
 *
 *       freeMemory(freeList,allocList,addr) returns number of bytes belongig to the address addr
 *       In all other cases freeMemory(freeList,allocList,addr) returns -1.
 */
{
	ELEMENT *previous = NULL;
    ELEMENT *current = *allocList;
    while(current != NULL)
    {
		if(current->addr == addr) // search for block to be freed
		{
			if(previous == NULL) // true if match found on first block
			{
				*allocList = (*allocList)->next; //the next alloc block becomes head of allocList
			}
			else
			{
				previous->next = current->next; //remove current block from allocList
			}
			int nrofBytes = current->size;
			free(current);
	
			/*INSERT BLOCK AT START OF FREELIST*/
			ELEMENT *freeblock = (ELEMENT *) malloc(sizeof(ELEMENT));
			freeblock->addr = addr;
			freeblock->size = nrofBytes;
			freeblock->next = *freeList;
			*freeList = freeblock;
			
			/*SORT & DEFRAG FREELIST*/
			sortList(*freeList);
			defragList(*freeList);
			
			return nrofBytes;
		}
		else
		{
			previous = current; 	 //keep a ptr to previous block
			current = current->next; //advance to next block
		}
	}
	return -1;

} /* freeMemory */


int claimMemory (ELEMENT ** freeList, ELEMENT ** allocList, int nrofBytes)
/* pre : nrofBytes > 0
 * post: If no memory block of nrofBytes available return -1
 *       Otherwise claimMemory(freeList,allocList,nrofBytes) returns the first
 *       address in the *freeList where a memory block of at least nrofBytes is present.
 *       This memory is allocated and not any more available.
 *       The newly allocated block is added to the *allocList and addr of the newly
 *       allocated block is returned
 */
{			
	ELEMENT *previous = NULL;
    ELEMENT *current = *freeList;
    if(current == NULL){return -1;}
    
	while(current->size < nrofBytes) //loop until enough free mem. is found
	{
		if(current->next == NULL)	//not enough mem. available
		{
			return -1;
		}
		previous = current;
		current = current->next;
	}
	
	int addr = current->addr; 
	current->addr = addr + nrofBytes;
	current->size -= nrofBytes; 
	
	if(current->size == 0)
	{
		if(previous == NULL) //first block had exactly enough memory
		{
			*freeList = (*freeList)->next;  //next block becomes new head
		}
		else
		{
			previous->next = current->next; //prev block linked to next block
		}
		free(current);
	}
	
	ELEMENT *allocblock = (ELEMENT*)malloc(sizeof(ELEMENT));
	allocblock->addr = addr;
	allocblock->size = nrofBytes;
	
	ELEMENT *temp, *prev = NULL;
	temp = *allocList; 
	if(temp != NULL) //allocList is not empty
	{
		while(temp->addr < addr)
		{
			prev = temp;
			temp = temp->next;
			if (temp == NULL) {break;}
		}
		if(prev == NULL) //add to front of list
		{
			allocblock->next = *allocList;
			*allocList = allocblock;
		}
		else
		{
			prev->next = allocblock;
			allocblock->next = temp;
		}
	}	
	else //allocList is empty
	{ 	 //add to front of list
		allocblock->next = NULL;
		*allocList = allocblock;
	}
	return addr;
	
} /* claimMemory */


void cleanList (ELEMENT ** list)
/* pre : list = NULL or a linear linked list of ELEMENT structures; the next pointer of the last element is NULL
 * post: the memory of the linked list associated with **list is cleaned
 */
{
	ELEMENT *current = *list; // get head of list
	ELEMENT *next = NULL;
	
	while(current != NULL)
	{
		next = current->next; 
		free(current);		 // free the mem. of current (variable still exists)
		current = next;		 // advance to next block
	}
	free(current);
	free(next);
	*list = NULL;
}


