/*
 * Copyright (C) 陈暮尘·(NightDust) 2020
 * All Rights Reserved
 *
 * Email：lingwangsheng249@gmail.com
 *
 * FileName：CLinkedList.c
 * CreateTime：2020/10/17 11:50
 * Description:B15 链表的构造与访问 
 *
 */

#include "CLinkedList.h"
#include<stdio.h>

node* createLinkedList(void) {

	node* n = (node*)malloc(sizeof(node));

	if (n != NULL)
	{
		n->next = NULL;
		return n;
	}
	return;
}

bool delLinkedList(node* n) {
	delLinkedListBackNode(n);
	free(n);
	return true;
}

_information createInformation(char* name, long id, char* address) {

	_information i = {
						.address = address,
						.id = id,
						.name = name
	};

	return i;
}

bool addLinkedListBackNode(node* n, _information i) {

	node* s = (node*)malloc(sizeof(node));

	if (s == NULL)
	{
		return false;
	}
	else
	{
		node* temp;
		s->information = i;
		s->next = NULL;
		if (n->next == NULL)
		{
			n->next = s;
		}
		else
		{
			temp = n;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = s;
		}
		return true;
	}
}

bool delLinkedListBackNode(node* n) {

	node* temp = n;

	if (n->next == NULL)
	{
		return false;
	}
	else
	{
		while (temp->next->next != NULL)
		{
			temp = temp->next;
		}
		free(temp->next);
		temp->next = NULL;
		return true;
	}
}

bool insertLinkedListNode(node* n, _information i, seat s) {

	node* insertNode = (node*)malloc(sizeof(node));

	if (s >= 1)
	{
		s--;
	}
	else if (s <= 0)
	{
		return false;
	}

	if (insertNode != NULL)
	{
		insertNode->information = i;
		node* temp = n;
		for (int Index = 0; Index < s; Index++)
		{
			if (temp->next != NULL)
			{
				temp = temp->next;
			}
			else if (temp->next == NULL)
			{
				break;
			}
		}
		if (temp->next == NULL)
		{
			insertNode->next = NULL;
			temp->next = insertNode;
		}
		else
		{
			insertNode->next = temp->next;
			temp->next = insertNode;
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool delLinkedListNode(node* n, seat s) {

	node* temp = n;

	if (s <= 1)
	{
		return false;
	}

	for (int Index = 0; Index < s; Index++)
	{
		if (temp->next != NULL)
		{
			temp = temp->next;
		}
		else
		{
			return false;
		}
	}

	node* temps = temp->next;
	temp->next = temp->next->next;
	free(temps);
	return true;

}

bool insteadLinkedListNode(node* n, _information i, seat s) {
	node* temp = n;

	if (s <= 1)
	{
		return false;
	}

	for (int Index = 0; Index < s; Index++)
	{
		if (temp->next != NULL)
		{
			temp = temp->next;
		}
		else
		{
			return false;
		}
	}
	temp->information = i;
	return true;
}

bool clrLinkedListNode(node* n) {
	node* temp = n, * temps = n;
	if (temp->next != NULL)
	{
		temp = temp->next;
		while (temp != NULL)
		{
			temps = temp->next;
			free(temp);
			temp = temps;
		}
		n->next = NULL;
	}
	else
	{
		return true;
	}
}

bool orderLinkedList(node* n, orderFunc func, oType type)
{
	node* tempA = n->next, * tempB = NULL;
	if (tempA == NULL || tempA->next == NULL)
	{
		return false;
	}
	for (tempA; tempA != NULL; tempA = tempA->next)
	{
		for (tempB = n->next; tempB->next != NULL; tempB = tempB->next)
		{

			if ((!func(tempB->information, tempB->next->information)) && type == OUP)
			{
				swapInf(tempB, tempB->next);
			}
			if (func(tempB->information, tempB->next->information) && type == ODOWN)
			{
				swapInf(tempB, tempB->next);
			}
		}
	}
}

int getLinkedListLong(node* n)
{
	node* temp = n;
	int longOfLinkedList = 0;
	while (temp->next != NULL)
	{
		temp = temp->next;
		longOfLinkedList++;
	}
	return longOfLinkedList;
}

bool swapInf(node* p, node* q)
{
	_information temp = p->information;
	p->information = q->information;
	q->information = temp;
	return true;
}

