#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

// 初始化队列
void QueueInit(Queue* q)
{
	//节点结构体的地址不能为空，断言
	assert(q);

	q->head = NULL;
	q->tail = NULL;
}

// 销毁队列（防止内存泄漏问题）
void QueueDestroy(Queue* q)
{
	//节点结构体的地址不能为空，断言
	assert(q);

	//队列为空时无法销毁
    //写法一：assert(q->head);
	assert(!QueueEmpty(q));//写法二

	QueueNode* cur = q->head;
	while (cur)
	{
		QueueNode* tmp = cur;
		cur = cur->next;
		free(tmp);//防止内存泄露
		tmp = NULL;//可写可不写，因为变量tmp在本次循环结束后就会销毁
	}
	q->head = q->tail = NULL;
}

// 队尾入队列
void QueuePush(Queue* q, QDataType data)
{
	//节点结构体的地址不能为空，断言
	assert(q);

	//开辟新节点放数据
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->data = data;
	newnode->next = NULL;

	//将新节点入队（队尾）
	
	//头指针为空时 - 就意味着 队伍为空，写一个函数进行判断队列是否为空
	//if (q->head == NULL)
	if (QueueEmpty(q))
	{
		q->head = q->tail = newnode;
	}
	else
	{
		//头指针不为空
		q->tail->next = newnode;
		q->tail = q->tail->next;
	}
}

// 队头出队列 - 头删
void QueuePop(Queue* q)
{
	//节点结构体的地址不能为空，断言
	assert(q);
	
	//队列为空时无法删除
	//写法一：assert(q->head);
	assert(!QueueEmpty(q));//写法二

	QueueNode* tmp = q->head;
	q->head = q->head->next;
	free(tmp);//防止内存泄露
	tmp = NULL;//可写可不写，因为变量tmp在函数结束时就会被销毁

	//当队列仅有一个元素时，出队后，队列为空，此时头指针为空但尾指针仍保留节点地址
	if (q->head == NULL)
		q->tail = NULL;
}

// 获取队列头部元素
QDataType QueueFront(Queue* q)
{
	//节点结构体的地址不能为空，断言
	assert(q);

	//队列为空时无法获取
	//写法一：assert(q->head);
	assert(!QueueEmpty(q));//写法二

	return q->head->data;
}

// 获取队列队尾元素
QDataType QueueBack(Queue* q)
{
	//节点结构体的地址不能为空，断言
	assert(q);

	//队列为空时无法获取
	//写法一：assert(q->head);
	assert(!QueueEmpty(q));//写法二

	return q->tail->data;
}

// 获取队列中有效元素个数 - 遍历累计
int QueueSize1(Queue* q)
{
	//节点结构体的地址不能为空，断言
	assert(q);

	//假设参数是头指针，可以尝试递归（不好判空），然而是结构体的地址。
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
	//假设参数是头指针，可以尝试递归
	QueueNode* cur = head;

	return head == NULL ? 0 : QueueSize2(head->next) + 1;
}

// 检测队列是否为空，如果为空返回1，如果非空返回0 
int QueueEmpty(Queue* q)
{
	//节点结构体的地址不能为空，断言
	assert(q);

	return q->head == NULL;
}