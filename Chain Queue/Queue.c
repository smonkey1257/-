#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

// ��ʼ������
void QueueInit(Queue* q)
{
	//�ڵ�ṹ��ĵ�ַ����Ϊ�գ�����
	assert(q);

	q->head = NULL;
	q->tail = NULL;
}

// ���ٶ��У���ֹ�ڴ�й©���⣩
void QueueDestroy(Queue* q)
{
	//�ڵ�ṹ��ĵ�ַ����Ϊ�գ�����
	assert(q);

	//����Ϊ��ʱ�޷�����
    //д��һ��assert(q->head);
	assert(!QueueEmpty(q));//д����

	QueueNode* cur = q->head;
	while (cur)
	{
		QueueNode* tmp = cur;
		cur = cur->next;
		free(tmp);//��ֹ�ڴ�й¶
		tmp = NULL;//��д�ɲ�д����Ϊ����tmp�ڱ���ѭ��������ͻ�����
	}
	q->head = q->tail = NULL;
}

// ��β�����
void QueuePush(Queue* q, QDataType data)
{
	//�ڵ�ṹ��ĵ�ַ����Ϊ�գ�����
	assert(q);

	//�����½ڵ������
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->data = data;
	newnode->next = NULL;

	//���½ڵ���ӣ���β��
	
	//ͷָ��Ϊ��ʱ - ����ζ�� ����Ϊ�գ�дһ�����������ж϶����Ƿ�Ϊ��
	//if (q->head == NULL)
	if (QueueEmpty(q))
	{
		q->head = q->tail = newnode;
	}
	else
	{
		//ͷָ�벻Ϊ��
		q->tail->next = newnode;
		q->tail = q->tail->next;
	}
}

// ��ͷ������ - ͷɾ
void QueuePop(Queue* q)
{
	//�ڵ�ṹ��ĵ�ַ����Ϊ�գ�����
	assert(q);
	
	//����Ϊ��ʱ�޷�ɾ��
	//д��һ��assert(q->head);
	assert(!QueueEmpty(q));//д����

	QueueNode* tmp = q->head;
	q->head = q->head->next;
	free(tmp);//��ֹ�ڴ�й¶
	tmp = NULL;//��д�ɲ�д����Ϊ����tmp�ں�������ʱ�ͻᱻ����

	//�����н���һ��Ԫ��ʱ�����Ӻ󣬶���Ϊ�գ���ʱͷָ��Ϊ�յ�βָ���Ա����ڵ��ַ
	if (q->head == NULL)
		q->tail = NULL;
}

// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* q)
{
	//�ڵ�ṹ��ĵ�ַ����Ϊ�գ�����
	assert(q);

	//����Ϊ��ʱ�޷���ȡ
	//д��һ��assert(q->head);
	assert(!QueueEmpty(q));//д����

	return q->head->data;
}

// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* q)
{
	//�ڵ�ṹ��ĵ�ַ����Ϊ�գ�����
	assert(q);

	//����Ϊ��ʱ�޷���ȡ
	//д��һ��assert(q->head);
	assert(!QueueEmpty(q));//д����

	return q->tail->data;
}

// ��ȡ��������ЧԪ�ظ��� - �����ۼ�
int QueueSize1(Queue* q)
{
	//�ڵ�ṹ��ĵ�ַ����Ϊ�գ�����
	assert(q);

	//���������ͷָ�룬���Գ��Եݹ飨�����пգ���Ȼ���ǽṹ��ĵ�ַ��
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
	//���������ͷָ�룬���Գ��Եݹ�
	QueueNode* cur = head;

	return head == NULL ? 0 : QueueSize2(head->next) + 1;
}

// �������Ƿ�Ϊ�գ����Ϊ�շ���1������ǿշ���0 
int QueueEmpty(Queue* q)
{
	//�ڵ�ṹ��ĵ�ַ����Ϊ�գ�����
	assert(q);

	return q->head == NULL;
}