/*
 * Author: Abdullah Altawaitan
 * Date: 9 October 2014
 * Description: an application that analyzes the frequency of the occurrence of words within two inputs files,a start file and an end file. The application will further analyze the change in frequency of specific words from the start file to end file, to determine the increase or decrease in the word frequencies. Finally, the program will output (using standard output) the five words that have increased the most and the five words that have decreased the most from the first input file to the second file.
*/

#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"
#include "trending.h"

int main(int argc, char* argv[])
{
	// Checking command line arguments
	if (argc != 3)
	{
		printf("\nUsage: trending startFile endFile\n\n");
		return -1; 
	}

	// Opening files for startFile and enfFile
	FILE* startFile = fopen(argv[1], "r"); 
	FILE* endFile = fopen(argv[2], "r");

	// checking the opening files are successfully opned
	if (startFile == NULL || endFile == NULL)
	{
		printf("Could not open the files!!\n");
		return -1; 
	}


	char string[150]; // to store the word 
	DList list; // list to insert the nodes inside it 
	DListInit(&list); // initilize the list 
	DListNode* currNode = list.head; // pointer to the head node of the list

    // loop through the startFile until the end of the file 
	while (!feof(startFile))
	{
		int storeScanf = 0; // to store the return value of fscanf
		storeScanf = fscanf(startFile, "%s", &string);
		
		// if we did not get a string, then break because this is the end of the file
		if (storeScanf != 1)
		{
			break;
		}

		// Character pointer to a memory of the same size of the string 
		char* word = (char *)malloc((strlen(string) + 1) * sizeof(char));
		// copying the string to the new memory location 
		strcpy(word, string);
		// convert the string to lowercase 
		word = lowerString(word);
		// DListNode for getting the return address if we find the node that contain the word 
		DListNode* find = DListSearch(&list, word);

		// if the word did not found in any node in the list
		if (find == NULL)
		{
			DListNode* newNode = (DListNode *)malloc(sizeof(DListNode));
			newNode->word = word;
			newNode->startCount = 1;
			newNode->endCount = 0;
			DListInsertAfter(&list, currNode, newNode);

			currNode = newNode;
		}
		else // if the word is found
		{
			find->startCount++;
            list.size++;
		}

	}
	
    // loop through the startFile until the end of the file
	while (!feof(endFile))
	{
		int storeScanf = 0;  // to store the return value of fscanf
		storeScanf = fscanf(endFile, "%s", &string);
		// if we did not get a string, then break because this is the end of the file
		if (storeScanf != 1)
		{
			break;
		}

		// Character pointer to a memory of the same size of the string 
		char* word = (char *)malloc((strlen(string) + 1) * sizeof(char));
		// copying the string to the new memory location
		strcpy(word, string);
		// convert the string to lowercase 
		word = lowerString(word);
		// DListNode for getting the return address if we find the node that contain the word 
		DListNode* find = DListSearch(&list, word);
		
		// if the word did not found in any node in the list
		if (find == NULL)
		{
			DListNode* newNode = (DListNode *)malloc(sizeof(DListNode));
			newNode->word = word;
			newNode->startCount = 0;
			newNode->endCount = 1;
			DListInsertAfter(&list, currNode, newNode);

			currNode = newNode;
		}
		else  // if the word is found
		{
			find->endCount++;
			list.size++;
		}
	}
	
	// Sort the list using Bubble sort from greatest to lowest    
	DListSort(&list);

	// Print Trending Up 5 words 
	PrintTrendingUp(&list);

	// Print Trending Down 5 words 
	PrintTrendingDown(&list);


	fclose(startFile);
	fclose(endFile);

	return 0; 
}