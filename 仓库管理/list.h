#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <stdlib.h>
typedef struct DataType
{
	int num;
	char name[20];
	char from[20];
	int count;
	float price;
	char date_of_product[15];
	char date_of_purchase[15];
	char people[10];
} DataType;

typedef struct Node
{
	DataType element;
	struct Node *next;
} Node;
typedef Node* List;
void Initialize (List *L);
int Insert (List L, DataType x);
void Display (List L);
void Delete (List L);
void Statistics (List L);

#endif
