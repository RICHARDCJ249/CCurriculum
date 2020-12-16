/*
 * Copyright (C) 陈暮尘·(NightDust) 2020   
 * All Rights Reserved
 *
 * Email：lingwangsheng249@gmail.com
 *
 * FileName：CLinkedList.h
 * CreateTime：2020/10/17 11:51
 * Description:B15 链表的构造与访问 
 *
 */

#pragma once
#ifndef CLinkedList
#define CLinkedList

#include <stdbool.h>
#include <malloc.h>

/// <summary>
/// 升降序枚举
/// OUP   升序
/// ODPWN 降序
/// </summary>
typedef enum 
{
	OUP = 10,
	ODOWN = 20
} oType;

/// <summary>
/// 排序回调函数
/// </summary>
typedef bool (*orderFunc)(_information, _information);

/// <summary>
/// 位置定义类型
/// </summary>
typedef int seat;

/// <summary>
/// 节点定义结构体
/// </summary>
typedef struct 
{
	char* name;
	long id;
	char* address;
}_information;

/// <summary>
/// 节点结构体
/// </summary>
typedef struct node
{
	struct node* next;
	_information information;
}node;

/// <summary>
/// 创建列表
/// </summary>
/// <returns>头结点指针</returns>
void createLinkedList(node**,_information);

/// <summary>
/// 创建信息结构
/// </summary>
/// <param name="name">学生姓名</param>
/// <param name="id">学生学号</param>
/// <param name="address">学生地址</param>
/// <returns></returns>
_information createInformation(char* name, long id, char* address);

/// <summary>
/// 插入链表尾部节点
/// </summary>
/// <param name="n">头节点指针</param>
/// <param name="i">尾部节点信息</param>
/// <returns>增加结果反馈</returns>
bool addLinkedListBackNode(node* n, _information i);

/// <summary>
/// 删除链表尾部节点
/// </summary>
/// <param name="n">头节点指针</param>
/// <returns>删除结果反馈</returns>
bool delLinkedListBackNode(node* n);

/// <summary>
/// 插入链表节点
/// </summary>
/// <param name="n">头结点指针</param>
/// <param name="i">插入节点信息</param>
/// <param name="s">插入节点位置</param>
/// <returns>插入结果反馈</returns>
bool insertLinkedListNode(node* n, _information i,seat s);

/// <summary>
/// 删除链表节点
/// </summary>
/// <param name="n">头结点指针</param>
/// <param name="s">删除节点的位置</param>
/// <returns>删除结果反馈</returns>
bool delLinkedListNode(node* n, seat s);

/// <summary>
/// 修改链表节点
/// </summary>
/// <param name="n">头节点指针</param>
/// <param name="i">修改节点信息</param>
/// <param name="s">替换节点位置</param>
/// <returns>替换结果反馈</returns>
bool insteadLinkedListNode(node* n, _information i, seat s);

/// <summary>
/// 删除链表
/// </summary>
/// <param name="n">头结点指针</param>
/// <returns>结果反馈</returns>
bool delLinkedList(node* n);

/// <summary>
/// 对链表进行排序
/// </summary>
/// <param name="n">头结点指针</param>
/// <param name="func">排序回调函数</param>
/// <param name="type">排序方法</param>
/// <returns>排序结果</returns>
bool orderLinkedList(node* n,orderFunc func,oType type);

/// <summary>
/// 返回链表长度
/// </summary>
/// <param name="n">头接点指针</param>
/// <returns>链表长度</returns>
int getLinkedListLong(node* n);

/// <summary>
/// 交换数据
/// </summary>
/// <param name="p">节点指针</param>
/// <param name="q">节点指针</param>
/// <returns>true</returns>
bool swapInf(node* p, node* q);

#endif // !CLinkedList
