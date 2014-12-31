/*
 * File: trending.h
 * Author: Abdullah Altawaitan
 * Date: October 9, 2014
 * Description: Declaration of functions.
 */
#include "stdio.h"
#include "dlist.h"

#ifndef TRENDING_H
#define TRENDING_H

//	A function to sort the list using Bubble Sort Algorithm
void DListSort(DList *list);


//	A function to print out the 5 most Trending UP words in the list
void PrintTrendingUp(DList *list);


//	A function to print out the 5 least Trending Down words in the list
void PrintTrendingDown(DList *list);


#endif
