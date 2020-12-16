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
#include <stdio.h>


bool createLinkedList(node **n,_information information) {

	*n = (node*)malloc(sizeof(node));

	if (*n != NULL)
	{
		(*n)->next = NULL;
		(*n)->information = information;
		return true;
	}
	return false;
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
		s->information = i;
		s->next = NULL;
		if (n->next == NULL)
		{
			n->next = s;
		}
		else
		{
			while (n->next != NULL)
			{
				n = n->next;
			}
			n->next = s;
		}
		return true;
	}
}

bool delLinkedListBackNode(node* n) {

	if (n->next == NULL)
	{
		return false;
	}
	else
	{
		while (n->next->next != NULL)
		{
			n = n->next;
		}
		free(n->next);
		n->next = NULL;
		return true;
	}
}

bool insertLinkedListNode(node* n, _information i, seat s) {

	node* insertNode = (node*)malloc(sizeof(node));

	if (s < 0)
	{
		return false;
	}
	if (insertNode != NULL)
	{
		insertNode->information = i;

		while (s--)
		{
			if (n->next != NULL)
			{
				n = n->next;
			}
			else
			{
				break;
			}
		}
		insertNode->next = n->next;
		n->next = insertNode;
	}
	else
	{
		return false;
	}
}

bool delLinkedListNode(node* n, seat s) {

	if (s <= 0)
	{
		return false;
	}

	while (s--)
	{
		if (n->next != NULL)
		{
			n = n->next;
		}
		else
		{
			return false;
		}
	}

	node* temp = n->next;
	n->next = n->next->next;
	free(temp);
	return true;

}

bool insteadLinkedListNode(node* n, _information i, seat s) {

	if (s < 0)
	{
		return false;
	}

	while (s--)
	{
		if (n->next != NULL)
		{
			n = n->next;
		}
		else
		{
			return false;
		}
	}
	n->information = i;
	return true;
}

bool delLinkedList(node* n) {
	node* temp = n, * temps = n;
	while (temp != NULL)
	{
		temps = temp->next;
		free(temp);
		temp = temps;
	}
	n->next = NULL;
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
