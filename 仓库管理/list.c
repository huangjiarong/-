#include "list.h"
#include <stdio.h>
#include <string.h>

void Initialize (List *L)
{
	(*L) = (Node *) malloc (sizeof(Node));
	(*L)->next = NULL;
}
/*
 * Insert in the last
 */
int Insert (List L, DataType x)
{
	List p = L;
	List Tmp;
	while (p->next != NULL)
		p = p->next;		//go to the last of the List;
	Tmp = (List) malloc(sizeof(struct Node));
	if (Tmp == NULL)
	{
		printf ("Out of space!");
		return 0;
	}
	Tmp->element.num = x.num;
	strcat (Tmp->element.name, x.name);
	strcat (Tmp->element.from, x.from);
	Tmp->element.count = x.count;
	Tmp->element.price = x.price;
	strcat (Tmp->element.date_of_product, x.date_of_product);
	strcat (Tmp->element.date_of_purchase, x.date_of_purchase);
	strcat (Tmp->element.people, x.people);
	Tmp->next = NULL;
	p->next = Tmp;
	return 1;
}

void Display (List L)
{
	L = L->next;
	while (L != NULL)
	{
		printf ("%5d  %15s  %15s  %3d  %5.1f  %15s  %15s  %15s\n", L->element.num, L->element.name, L->element.from, L->element.count, L->element.price, L->element.date_of_product, L->element.date_of_purchase, L->element.people);
		L = L->next;
	}
}

void Delete (List L)
{
	Node *tmp;
	while (L->next->next != NULL)
		L = L->next;
	tmp = L->next;
	L->next = NULL;
	free (tmp);
}

void Statistics (List L)
{
	char factory[20];
	printf ("Please input the factory that you want to statistics: ");
	scanf ("%s", factory);
	getchar ();

	L = L->next;
	double all_value = 0;
	while (L != NULL)
	{
		all_value += L->element.count * L->element.price;
		if (strcmp(factory, L->element.from) == 0)
		{
			printf ("The factory %s has %d %s, and the price of one of them is %f RMB.\n", L->element.from, L->element.count, L->element.name, L->element.price);
		}
		L = L->next;
	}
	printf ("All prices of the productions in warehouse is %lf RMB.\n", all_value);
}
