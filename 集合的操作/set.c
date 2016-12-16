#include "set.h"
#include <stdbool.h>

void Initialize (Set *S)
{
	(*S) = (Node *) malloc (sizeof(Node));
	(*S)->next = NULL;
}
/*
 * Insert x in the last Node of the Set S;
 * If x is existed, do nothing and return false;
 */
bool Insert (Set S, DataType x)
{
	if (In_Set(S, x))
	{
		return false;
	}
	Set Tmp;
	while (S->next != NULL)
		S = S->next;		//go to the last Node of the Set;
	Tmp = (Set) malloc(sizeof(struct Node));
	if (Tmp == NULL)
	{
		printf ("Out of space!");
		return false;
	}
	Tmp->element = x;
	Tmp->next = NULL;
	S->next = Tmp;
	return true;
}

bool In_Set (Set S, DataType x)
{
	while (S->next != NULL)
	{
		S = S->next;
		if (S->element == x)
			return true;
	}
	return false;
}

void Display (Set S)
{
	S = S->next;
	while (S != NULL)
	{
		printf ("%d  ", S->element);
		S = S->next;
	}
}

/*
 * Delete x from set S
 */
bool Delete (Set S, DataType x)
{
	Node *Tmp;
	if (In_Set(S, x))
	{
		while (S->next->element != x)
		{
			S = S->next;
		}
		Tmp = S->next;
		S->next = S->next->next;
		free (Tmp);
		return true;
	}
	printf ("%d is not in Set.\n", x);
	return false;
}

Set Union (Set S1, Set S2)
{
	Set _union;
	Initialize (&_union);

	S1 = S1->next;
	while (S1 != NULL)
	{
		Insert (_union, S1->element);
		S1 = S1->next;
	}

	Set S = S2->next;
	while (S != NULL)
	{
		if (! In_Set(_union, S->element))
		{
			Insert (_union, S->element);
		}
		S = S->next;
	}

	return _union;
}

Set Intersection (Set S1, Set S2)
{
	Set intersection;
	Initialize (&intersection);

	Set S = S2->next;
	while (S != NULL)
	{
		if (In_Set(S1, S->element))
		{
			Insert (intersection, S->element);
		}
		S = S->next;
	}
	return intersection;
}

Set Symmetric_diff (Set S1, Set S2)
{
	Set _union = Union (S1, S2);
	Set intersection = Intersection (S1, S2);
	Set symm_diff = _union;

	Set S = intersection->next;
	while (S != NULL)
	{
		Delete (symm_diff, S->element);
		S = S->next;
	}

	return symm_diff;
}
