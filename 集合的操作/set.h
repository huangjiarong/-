#ifndef _SET_H
#define _SET_H_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef int DataType;
typedef struct Node
{
	DataType element;
	struct Node *next;
} Node;
typedef Node* Set;
void Initialize (Set *S);
bool Insert (Set S, DataType x); //若x不存在于集合，便将元素为x的节点插入到集合最后的节点
bool In_Set (Set S, DataType x);
bool Delete (Set S, DataType x); //将集合里元素为x的节点删除
void Display (Set S);
Set Union (Set S1, Set S2); //求并集
Set Intersection (Set S1, Set S2); //求交集
Set Symmetric_diff (Set S1, Set S2); //求对称差集

#endif
