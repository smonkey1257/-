#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//创建节点结构体（数据域，指针域）
typedef int SLDataType;
typedef struct SLNode
{
	SLDataType data;
	struct SLNode* next;
}SLNode;

// 动态申请一个节点
SLNode* BuySListNode(SLDataType x);

// 单链表打印
void SLPrint(SLNode* plist);

// 单链表尾插
void SLPushBack(SLNode** pplist, SLDataType x);

// 单链表的头插
void SLPushFront(SLNode** pplist, SLDataType x);

// 单链表的尾删
void SLPopBack(SLNode** pplist);

// 单链表头删
void SLPopFront(SLNode** pplist);

// 单链表查找
SLNode* SLFind(SLNode* plist, SLDataType x);

// 单链表在pos位置之前插入x
void SLInsert(SLNode** pplist, SLNode* pos, SLDataType x);

// 单链表在pos位置之后插入x
void SLInsertAfter(SLNode* pos, SLDataType x);

// 单链表删除pos位置的值
void SLErase(SLNode** pplist, SLNode* pos);

// 单链表删除pos位置之后的值
void SLEraseAfter(SLNode* pos);

//清空链表
void SLDestory(SLNode** pplist);