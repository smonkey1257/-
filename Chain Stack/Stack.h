#pragma once

//����ͷ�ļ�����
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//ջ�ڵ�ṹ������
typedef int STDataType;
typedef struct StackNode
{
	STDataType data;
	struct StackNode* next;
}ST;

//ջ����ؽӿ�����

//��ʼ��
void StackInit(ST** pphead);

//�����½ڵ�
ST* BuySTNode(const STDataType x);

//��ջ(ͷ��)
void StackPush(ST** pphead, const STDataType x);

//��ջ��ͷɾ��
void StackPop(ST** pphead);

//��ӡ(���øĶ�ͷָ�벻�ô�������const�ؼ��ֱ�֤��ȫ��)
void StackPrint(ST* phead);

//�п�
bool isStackEmpty(ST* phead);

//����ջ��Ԫ��
STDataType StackTop(ST* phead);

//����ջ����Ч���ݸ���
int StackSize(ST* phead);

//����ջ
void StackDestroy(ST** pphead);