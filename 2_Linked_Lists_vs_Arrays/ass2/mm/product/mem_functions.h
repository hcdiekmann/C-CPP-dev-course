#ifndef _MEM_FUNCTIONS_H__
#define _MEM_FUNCTIONS_H__
/* SD ass 2: memory manager	 */
/* Author : C. Diekmann      */
/* Version : 1.0			 */

typedef struct element
{
    int                 addr;
    int                 size;
    struct element *    next;
} ELEMENT;

//Sorts the singly linked list according to addr accending
void sortList(ELEMENT *list);

//Merges consecutive blocks of free memory
void defragList(ELEMENT *list);


#endif
