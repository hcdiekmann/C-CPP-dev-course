
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct element
{
    int                 addr;
    int                 size;
    struct element *    next;
} ELEMENT;

//Sorts the singly linked list according to addr accending
void sortList(ELEMENT *list){
	int swapped = 0;
	ELEMENT *temp, *ptr = NULL;
	temp = list;
	do
	{
		while (temp->next != ptr)
		{
			if (temp->addr > temp->next->addr) // swap addr & size
			{
				int a = temp->addr;
				temp->addr = temp->next->addr;
				temp->next->addr = a;
				
				int s = temp->size;
				temp->size = temp->next->size;
				temp->next->size = s;
				
				swapped = 1;
			}
			temp = temp->next;
			if(temp->next == NULL){swapped = 0;break;}
		}
		ptr = temp;
	}
	while (swapped);
}

//Merges consecutive blocks of free memory
void defragList(ELEMENT *list){
	//run twice to ensure all consecutive blocks are merged
	for (int i=0; i < 2; i++){
		ELEMENT *current , *next = NULL; 
		current = list;
		do 
		{
			next = current->next;
			if (next == NULL) {break;} 
			if((current->addr + current->size) == next->addr)
			{
				current->size += next->size;
				current->next = next->next;
				free(next);
			}
			current = current->next;
		} 
		while(current != NULL);
	}
}





