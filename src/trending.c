/*
* File: trending.c
* Author: Abdullah Altawaitan
* Date: October 9, 2014
* Description: Implementation of functions.
*/

#include <stdio.h>
#include "trending.h"
#include "dlist.h"

//	A function to sort the list using Bubble Sort Algorithm
void DListSort(DList *list)
{
	DListNode* temp = list->head;
	int val = 0; 
	int nextVal = 0;
	int swap = 0;

	do 
	{
		swap = 0;
		temp = list->head;
		int val = 0;
		int nextVal = 0;
		while (temp != NULL)
		{
			val = (temp->endCount - temp->startCount);
			if (temp->next == NULL)
			{
				break;
			}
			nextVal = (temp->next->endCount - temp->next->startCount);
			if (val < nextVal)
			{
				int eCount = temp->endCount;
				int sCount = temp->startCount;
				char *word = temp->word;

				temp->endCount = temp->next->endCount;
				temp->startCount = temp->next->startCount;
				temp->word = temp->next->word;

				temp->next->endCount = eCount;
				temp->next->startCount = sCount;
				temp->next->word = word;

				swap = 1;
			}
			temp = temp->next;
		}
	} while (swap != 0);
}

//	A function to print out the 5 most Trending UP words in the list
void PrintTrendingUp(DList *list)
{
	if (list != NULL)
	{
		printf("Trending Up:\n");
		DListNode *temp = list->head;
		int i = 0;

		for (i = 0; i < 5; i++)
		{
			if (temp != NULL)
			{
				printf("%s (%ld)\n", temp->word, (temp->endCount - temp->startCount));
				temp = temp->next;
			}
		}
	}
}

//	A function to print out the 5 least Trending Down words in the list
void PrintTrendingDown(DList *list)
{
	if (list != NULL)
	{
		printf("\nTrending Down:\n");
		DListNode *temp = list->tail;
		int i = 0;

		for (i = 0; i < 5; i++)
		{
			if (temp != NULL)
			{
				printf("%s (%ld)\n", temp->word, (temp->endCount - temp->startCount));
				temp = temp->prev;
			}
		}
	}
}