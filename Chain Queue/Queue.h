#pragma once

/*
��ͷ�����ѭ������ʵ�ֶ��У�
�����ص㣺ֻ�����ڶ�ͷ�����ݣ���β������
*/

//����ͷ�ļ�����
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//���нڵ�
typedef int QDataType;

typedef struct QueueNode
{
	QDataType data;
	struct QListNode* next;
}QueueNode;

//���нṹ
/*
���ڶ��нṹ�������ԣ�ֻ����������β�����룬
Ϊ�˱���ÿ�ζ�Ҫ��β����ͷָ���βָ�����Ϊһ���ṹ��������
*/
typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;

// ��ʼ������
void QueueInit(Queue* q);

// ���ٶ���
void QueueDestroy(Queue* q);

// ��β�����
void QueuePush(Queue* q, QDataType data);

// ��ͷ������
void QueuePop(Queue* q);

// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* q);

// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* q);

// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* q);

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q);