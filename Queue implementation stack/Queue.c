#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

//ʵ�ֶ��еĺ����ӿ�

// ��ʼ������
void QueueInit(Queue* q)
{
	assert(q);
	q->head = NULL;
	q->tail = NULL;
}

// ���ٶ��У���ֹ�ڴ�й©���⣩
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

// ��β�����
void QueuePush(Queue* q, QDataType data)
{
	assert(q);

	//�����½ڵ������
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

// ��ͷ������ - ͷɾ
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

// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->head->data;
}

// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->tail->data;
}

// ��ȡ��������ЧԪ�ظ��� - �����ۼ�
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

// ��ȡ��������ЧԪ�ظ��� - ����
int QueueSize2(QueueNode* head)
{
	QueueNode* cur = head;
	return head == NULL ? 0 : QueueSize2(head->next) + 1;
}

// �������Ƿ�Ϊ�գ����Ϊ�շ���1������ǿշ���0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->head == NULL;
}

//���ö���ʵ��ջ�ĺ����ӿ�