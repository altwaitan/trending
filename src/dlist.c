/*
* File: dlist.c
* Author: Abdullah Altawaitan
* Date: October 9, 2014
* Description: Implementation of functions.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "bool.h"
#include "dlist.h"

//	A function to Initilize the list to size of zero, and head and tail to NULL.
void DListInit(DList* list)
{
	if (list != NULL)
	{
		list->size = 0;
		list->head = NULL;
		list->tail = NULL;
	}
	return;
}

//	A function to remove all the nodes inside the list, and free them from the memory, and then destroy the list.
void DListDestroy(DList* list)
{
	if (list != NULL)
	{
		DListNode* temp = list->head;
		DListNode* tempnext = (DListNode *)malloc(sizeof(DListNode));
		temp = list->head;

		if (temp != NULL)
		{
			tempnext = temp->next;
			DListRemove(list, temp);
			temp = tempnext;
		}

		free(temp);
		free(tempnext);
		DListInit(list);
	}
	
}

//	A function that insert the newNode after the currNode in the list. Also it takes care of the head and the tail if necessary. It return true if the insert is done.
bool DListInsertAfter(DList* list, DListNode* currNode, DListNode* newNode)
{
	bool result = false;

	if (list != NULL)
	{
		result = true;
		if (currNode == NULL)
		{
			return DListInsertBefore(list, list->head, newNode);
		}
		else
		{
			newNode->next = currNode->next;
			newNode->prev = currNode;

			if (newNode->next != NULL)
			{
				newNode->next->prev = newNode;
			}

			currNode->next = newNode;
		}
		DListUpdateHeadTail(list, currNode, newNode);
		list->size++;
	}

	return result;

}

//	A function that insert the newNode before the currNode in the list. Also it takes care of the head and the tail if necessary. It return true if the insert is done.
bool DListInsertBefore(DList* list, DListNode* currNode, DListNode* newNode)
{
	bool result = false;
	if (list != NULL)
	{
		result = true;

		if (currNode == NULL)
		{
			newNode->next = list->head;
			newNode->prev = NULL;

			if (list->head != NULL)
			{
				list->head->prev = newNode;
			}
		}
		else
		{
			if (newNode != NULL)
			{
				newNode->next = currNode;
				newNode->prev = currNode->prev;

				if (currNode->prev != NULL)
				{
					currNode->prev->next = newNode;
				}

				currNode->prev = newNode;
			}
		}

		DListUpdateHeadTail(list, currNode, newNode);
		list->size++;
	}

	return result;

}

//	A function that returns the address of the node that the word was found in. Else it returns NULL.

DListNode* DListSearch(DList* list, char* key)
{
	DListNode *temp = list->head;

	if (list != NULL)
	{

		// Convert the string to lowercase 
		key = lowerString(key);

		// If we find the word, the function will return the address of the node that we found the word in. Else it will return NULL
		while (temp != NULL)
		{
			if (strcmp(temp->word, key) == 0)
			{
				return temp;
			}
			temp = temp->next;
		}

	}
	return NULL;
}

//	A function that removes a currNode from the list, and takes care of the head and tail. It return true if the remove is done.
bool DListRemove(DList* list, DListNode* currNode)
{
    bool result = false;
	if (list != NULL)
	{
        result = true;
		DListNode* tempNext = currNode->next;
		DListNode* tempPrev = currNode->prev;

		if (tempNext != NULL)
		{
			tempNext->prev = tempPrev;
		}
		if (tempPrev != NULL)
		{
			tempPrev->next = tempNext;
		}
		if (currNode->prev == NULL)
		{
			list->head = tempNext;
		}
		if (currNode->next == NULL)
		{
			list->tail = tempPrev;
		}

		free(tempNext);
		free(tempPrev);
		
	}
    return result;
}

//	A function that takes care of updating the head and the tail of the list.
void DListUpdateHeadTail(DList *list, DListNode *currNode, DListNode *newNode)
{
	if (list != NULL)
	{
		if (currNode != NULL)
		{
			if (currNode->next == NULL)
			{
				list->tail = currNode;
			}
			if (currNode->prev == NULL)
			{
				list->head = currNode;
			}
		}

		if (newNode != NULL)
		{
			if (newNode->next == NULL)
			{
				list->tail = newNode;
			}
			if (newNode->prev == NULL)
			{
				list->head = newNode;
			}
		}
	}
}

//	A function that prints out the nodes in the list.
void PrintList(DList *list)
{
	if (list != NULL)
	{
		DListNode *temp = list->head;

		printf("*************** The list ******************\n");
		printf("*******************************************\n");

		printf("The list size is: %d\n", list->size);
		printf("The list HEAD pointer to: %s\n", list->head->word);
		printf("The list TAIL pointer to: %s\n", list->tail->word);

		while (temp != NULL)
		{
			printf("%s", temp->word);
			printf("\tCount ( %ld )\n", (temp->endCount - temp->startCount));
			temp = temp->next;
		}
	}
}

//	A function that convert the string into lowercase.
char* lowerString(char* key)
{
	int i = 0;
	unsigned long size = strlen(key);

	for (i = 0; i < size; i++)
	{
		key[i] = tolower(key[i]);
	}


	return key;
}
