#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

//实现队列的函数接口

// 初始化队列
void QueueInit(Queue* q)
{
	assert(q);
	q->head = NULL;
	q->tail = NULL;
}

// 销毁队列（防止内存泄漏问题）
void QueueDestroy(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	QueueNode* cur = q->head;
	while (cur)
	{
		QueueNode* tmp = cur;
		cur = cur->next;
		free(tmp);
		tmp = NULL;
	}
	q->head = q->tail = NULL;
}

// 队尾入队列
void QueuePush(Queue* q, QDataType data)
{
	assert(q);

	//开辟新节点放数据
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->data = data;
	newnode->next = NULL;

	if (QueueEmpty(q))
	{
		q->head = q->tail = newnode;
	}
	else
	{
		q->tail->next = newnode;
		q->tail = q->tail->next;
	}
}

// 队头出队列 - 头删
void QueuePop(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	QueueNode* tmp = q->head;
	q->head = q->head->next;
	free(tmp);
	tmp = NULL;
	if (q->head == NULL)
		q->tail = NULL;
}

// 获取队列头部元素
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->head->data;
}

// 获取队列队尾元素
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->tail->data;
}

// 获取队列中有效元素个数 - 遍历累计
int QueueSize1(Queue* q)
{
	assert(q);

	int count = 0;
	QueueNode* cur = q->head;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

// 获取队列中有效元素个数 - 分治
int QueueSize2(QueueNode* head)
{
	QueueNode* cur = head;
	return head == NULL ? 0 : QueueSize2(head->next) + 1;
}

// 检测队列是否为空，如果为空返回1，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->head == NULL;
}

//利用队列实现栈的函数接口