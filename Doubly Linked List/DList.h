#pragma once

/*实现带头双向循环链表*/

//常用头文件包含
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//双向链表节点声明
typedef int DLTDataType;
typedef struct DoubleListNode
{
	DLTDataType data;
	struct DoubleListNode* prev;
	struct DoubleListNode* next;
}DLNode;

//初始化
DLNode* DListInit();

//尾插
void DListPushBack(DLNode* phead, DLTDataType x);

//多个位置要创立新节点，归并
DLNode* BuyListNode(DLTDataType x);

//打印链表
void DListPrint(DLNode* phead);

//尾删
void DListPopBack1(DLNode* phead);//声明有问题void DListPopBack(DLNode* phead);
void DListPopBack2(DLNode* phead);

//头插
void DListPushFront(DLNode* phead, DLTDataType x);

//头删
void DListPopFront(DLNode* phead);

//查找某个元素
DLNode* DListFind(DLNode* phead, DLTDataType x);

//指定位置的插入
void DListInsert(DLNode* phead, DLTDataType x);

//指定位置删除
void DListErase(DLNode* pos);

//销毁链表
void DListDestroy(DLNode* phead);