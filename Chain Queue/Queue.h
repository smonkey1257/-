#pragma once

/*
无头单项非循环链表实现队列，
队列特点：只允许在队头出数据，队尾入数据
*/

//常用头文件包含
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//队列节点
typedef int QDataType;

typedef struct QueueNode
{
	QDataType data;
	struct QListNode* next;
}QueueNode;

//队列结构
/*
由于队列结构的特殊性，只允许在链表尾部插入，
为了避免每次都要找尾，将头指针和尾指针组合为一个结构体来管理
*/
typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;

// 初始化队列
void QueueInit(Queue* q);

// 销毁队列
void QueueDestroy(Queue* q);

// 队尾入队列
void QueuePush(Queue* q, QDataType data);

// 队头出队列
void QueuePop(Queue* q);

// 获取队列头部元素
QDataType QueueFront(Queue* q);

// 获取队列队尾元素
QDataType QueueBack(Queue* q);

// 获取队列中有效元素个数
int QueueSize(Queue* q);

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q);