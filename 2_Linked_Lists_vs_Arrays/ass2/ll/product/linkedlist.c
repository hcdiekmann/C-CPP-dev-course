/* SD exercise 1: simple linked list API */
/* Author : R. Frenken                   */
/* Version : 1.0			 */
#include "linkedlist.h"
#include <stdlib.h>

/***************************************************/
/* If *list == NULL, a new list should be created, */
/* otherwise prepend a new ITEM with value value   */
/* to the existing list                            */
/* Returns -1 if not enough memory, otherwise 0    */
/***************************************************/

int add_first(ITEM **list, int value)
{
	ITEM *item = (ITEM *) malloc(sizeof(ITEM));
	if(item == NULL){
		return -1;
	}
	item->value = value;
	item->next = NULL;

	if(*list != NULL){/* when list is not empty */
		item->next = *list;// point link of added item to prev. head
	}
	*list = item;
	return 0;
}

/***************************************************/
/* If *list == NULL, a new list should be created, */
/* otherwise append a new ITEM with value value to */
/* the existing list                               */
/* Returns -1 if not enough memory, otherwise 0    */
/***************************************************/

int add_last(ITEM **list, int value)
{
	ITEM *temp;
	ITEM *item = (ITEM *) malloc(sizeof(ITEM));
	if(item == NULL){
		return -1;
	}

	item->value = value;
	item->next = NULL;
	
	if(*list == NULL){ // when empty
		*list = item;
	}
    else{
		temp = *list; //use temp to prevnt changing list
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = item; //point last node to new item
	}
	return 0;
}

/****************************************************/
/* Insert a new item after current item c_item      */
/* Returns -1 if not enough memory, c_item == NULL, */
/* *list == NULL or c_item not found, otherwise 0   */
/****************************************************/

int add_after(ITEM *list, ITEM *c_item, int value)
{
	ITEM *item = (ITEM *) malloc(sizeof(ITEM));
	if(item == NULL ||  list == NULL || c_item == NULL){
		return -1;
	}
	ITEM *temp;
	temp = c_item->next;
	c_item->next = item;
	item->value = value;
    item->next = temp;
	return 0;
}


/***************************************************/
/* Remove first item of the list                   */
/* Returns -1 if list==NULL, otherwise 0           */
/***************************************************/

int rem_first(ITEM **list)
{
	if(*list == NULL){
		return -1;
	}
	ITEM *temp;
	temp = *list;
	*list = (*list)->next;
	free(temp);
	return 0;
}

/***************************************************/
/* Remove last item of the list                    */
/* Returns -1 if list==NULL, otherwise 0           */
/***************************************************/

int rem_last(ITEM **list)
{
	if(*list == NULL){
		return -1;
	}
	
	ITEM *temp, *ptr;
	temp = *list; // use temp to prevent changing the head (*list)
	while(temp->next != NULL){
		ptr = temp; // to keep track of second last node
		temp = temp->next;
	}
	ptr->next = NULL;
	free(temp);
	return 0;
}

/***************************************************/
/* Remove item after c_item of the list            */
/* Returns -1 list==NULL, c_item not found or      */
/* c_item is the last_element                      */
/***************************************************/

int rem_after(ITEM *list, ITEM *c_item)
{
	if(list == NULL || c_item->next == NULL){
		return -1;
	}
	
	ITEM *temp;
	temp = c_item->next;
	c_item->next = c_item->next->next;
	free(temp);
	return 0;
}

/*********************************************************/
/* All dynamic memory allocated to the list is freed     */
/*********************************************************/

void clean(ITEM *list)
{
	ITEM *temp = list;
	ITEM *next = NULL;
	while(temp != NULL){
		next = temp->next;
		free(temp);
		temp = next;
	}
	list = NULL;
	return;
}

