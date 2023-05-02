#pragma once

/*ʵ�ִ�ͷ˫��ѭ������*/

//����ͷ�ļ�����
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//˫������ڵ�����
typedef int DLTDataType;
typedef struct DoubleListNode
{
	DLTDataType data;
	struct DoubleListNode* prev;
	struct DoubleListNode* next;
}DLNode;

//��ʼ��
DLNode* DListInit();

//β��
void DListPushBack(DLNode* phead, DLTDataType x);

//���λ��Ҫ�����½ڵ㣬�鲢
DLNode* BuyListNode(DLTDataType x);

//��ӡ����
void DListPrint(DLNode* phead);

//βɾ
void DListPopBack1(DLNode* phead);//����������void DListPopBack(DLNode* phead);
void DListPopBack2(DLNode* phead);

//ͷ��
void DListPushFront(DLNode* phead, DLTDataType x);

//ͷɾ
void DListPopFront(DLNode* phead);

//����ĳ��Ԫ��
DLNode* DListFind(DLNode* phead, DLTDataType x);

//ָ��λ�õĲ���
void DListInsert(DLNode* phead, DLTDataType x);

//ָ��λ��ɾ��
void DListErase(DLNode* pos);

//��������
void DListDestroy(DLNode* phead);