/*
* File: dlist.h
* Author: Abdullah Altawaitan
* Date: October 9, 2014
* Description: Declaration of functions.
*/
#include "bool.h"

#ifndef DLIST_H
#define DLIST_H

//	A struct type for the DListNode for a doubly linked list to store the word and the startCount in the startFile and endCount for the endFile, with two pointers to next node and previous node.
typedef struct DListNode_struct {
	char *word; 
	unsigned long startCount; 
	unsigned long endCount; 
	struct DListNode_struct *next; 
	struct DListNode_struct *prev; 
} DListNode;


//	A struct the list that can store the nodes for a doubly linked list inside it. It has the size which indicate how many nodes inside the list and head and tail pointers to know the beginning and the ending of the list.
typedef struct DList_struct {
	int size; 
	DListNode *head; 
	DListNode *tail; 
} DList;

//	A function to Initilize the list to size of zero, and head and tail to NULL.
void DListInit(DList* list);


//	A function to remove all the nodes inside the list, and free them from the memory, and then destroy the list.
void DListDestroy(DList* list);


//	A function that insert the newNode after the currNode in the list. Also it takes care of the head and the tail if necessary. It return true if the insert is done.
bool DListInsertAfter(DList* list, DListNode* currNode, DListNode* newNode);


//	A function that insert the newNode before the currNode in the list. Also it takes care of the head and the tail if necessary. It return true if the insert is done.
bool DListInsertBefore(DList* list, DListNode* currNode, DListNode* newNode);


//	A function that returns the address of the node that the word was found in. Else it returns NULL.
DListNode* DListSearch(DList* list, char* key);


//	A function that removes a currNode from the list, and takes care of the head and tail. It return true if the remove is done.
bool DListRemove(DList* list, DListNode* currNode);


//	A function that takes care of updating the head and the tail of the list.
void DListUpdateHeadTail(DList *list, DListNode *currNode, DListNode *newNode);


//	A function that prints out the nodes in the list.
void PrintList(DList *list);


//	A function that convert the string into lowercase.
char* lowerString(char* key);



#endif
