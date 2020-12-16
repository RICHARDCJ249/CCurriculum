/*
 * Copyright (C) ��ĺ����(NightDust) 2020   
 * All Rights Reserved
 *
 * Email��lingwangsheng249@gmail.com
 *
 * FileName��CLinkedList.h
 * CreateTime��2020/10/17 11:51
 * Description:B15 ����Ĺ�������� 
 *
 */

#pragma once
#ifndef CLinkedList
#define CLinkedList

#include <stdbool.h>
#include <malloc.h>

/// <summary>
/// ������ö��
/// OUP   ����
/// ODPWN ����
/// </summary>
typedef enum 
{
	OUP = 10,
	ODOWN = 20
} oType;

/// <summary>
/// ����ص�����
/// </summary>
typedef bool (*orderFunc)(_information, _information);

/// <summary>
/// λ�ö�������
/// </summary>
typedef int seat;

/// <summary>
/// �ڵ㶨��ṹ��
/// </summary>
typedef struct 
{
	char* name;
	long id;
	char* address;
}_information;

/// <summary>
/// �ڵ�ṹ��
/// </summary>
typedef struct node
{
	struct node* next;
	_information information;
}node;

/// <summary>
/// �����б�
/// </summary>
/// <returns>ͷ���ָ��</returns>
void createLinkedList(node**,_information);

/// <summary>
/// ������Ϣ�ṹ
/// </summary>
/// <param name="name">ѧ������</param>
/// <param name="id">ѧ��ѧ��</param>
/// <param name="address">ѧ����ַ</param>
/// <returns></returns>
_information createInformation(char* name, long id, char* address);

/// <summary>
/// ��������β���ڵ�
/// </summary>
/// <param name="n">ͷ�ڵ�ָ��</param>
/// <param name="i">β���ڵ���Ϣ</param>
/// <returns>���ӽ������</returns>
bool addLinkedListBackNode(node* n, _information i);

/// <summary>
/// ɾ������β���ڵ�
/// </summary>
/// <param name="n">ͷ�ڵ�ָ��</param>
/// <returns>ɾ���������</returns>
bool delLinkedListBackNode(node* n);

/// <summary>
/// ��������ڵ�
/// </summary>
/// <param name="n">ͷ���ָ��</param>
/// <param name="i">����ڵ���Ϣ</param>
/// <param name="s">����ڵ�λ��</param>
/// <returns>����������</returns>
bool insertLinkedListNode(node* n, _information i,seat s);

/// <summary>
/// ɾ������ڵ�
/// </summary>
/// <param name="n">ͷ���ָ��</param>
/// <param name="s">ɾ���ڵ��λ��</param>
/// <returns>ɾ���������</returns>
bool delLinkedListNode(node* n, seat s);

/// <summary>
/// �޸�����ڵ�
/// </summary>
/// <param name="n">ͷ�ڵ�ָ��</param>
/// <param name="i">�޸Ľڵ���Ϣ</param>
/// <param name="s">�滻�ڵ�λ��</param>
/// <returns>�滻�������</returns>
bool insteadLinkedListNode(node* n, _information i, seat s);

/// <summary>
/// ɾ������
/// </summary>
/// <param name="n">ͷ���ָ��</param>
/// <returns>�������</returns>
bool delLinkedList(node* n);

/// <summary>
/// �������������
/// </summary>
/// <param name="n">ͷ���ָ��</param>
/// <param name="func">����ص�����</param>
/// <param name="type">���򷽷�</param>
/// <returns>������</returns>
bool orderLinkedList(node* n,orderFunc func,oType type);

/// <summary>
/// ����������
/// </summary>
/// <param name="n">ͷ�ӵ�ָ��</param>
/// <returns>������</returns>
int getLinkedListLong(node* n);

/// <summary>
/// ��������
/// </summary>
/// <param name="p">�ڵ�ָ��</param>
/// <param name="q">�ڵ�ָ��</param>
/// <returns>true</returns>
bool swapInf(node* p, node* q);

#endif // !CLinkedList
