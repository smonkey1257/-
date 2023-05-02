#define _CRT_SECURE_NO_WARNINGS 1

#include "DList.h"

//��ʼ��
/*
1. ��һ���ڱ�λ��ͷ�ڵ�
2. ����ͷ�ڵ�ĵ�ַ������Ҫ������
3. prevָ���Լ���nextҲָ���Լ�
*/
DLNode* DListInit()
{
	DLNode* phead = (DLNode*)malloc(sizeof(DLNode));
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

//���λ��Ҫ�����½ڵ㣬�鲢
DLNode* BuyListNode(DLTDataType x)
{
	//�����½ڵ�
	DLNode* newnode = (DLNode*)malloc(sizeof(DLNode));
	//����ڵ㿪��ʧ�ܣ����쳣�˳�
	if (!newnode)
	{
		printf("malloc failde\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;

	return newnode;
}

//β��
/*
1. ����Ҫ�Ķ�ͷָ�룬���ô�����
2. Ҫ�Ķ��ڱ�λͷ�ڵ�ĳ�Ա�����ṹ��ĵ�ַ
*/
void DListPushBack(DLNode* phead, DLTDataType x)
{
	assert(phead);

	////�����½ڵ�
	//DLNode* newnode = BuyListNode(x);

	//DLNode* tail = phead->prev;
	////�����ӹ�ϵ
	//tail->next = newnode;
	//newnode->prev = tail;

	//newnode->next = phead;
	//phead->prev = newnode;

	DListInsert(phead, x);

}

//��ӡ����
void DListPrint(DLNode* phead)
{
	assert(phead);//ͷ�ڵ�ĵ�ַ����Ϊ��
	//assert(phead->next != phead);
	
	//���ڱ�λ�ڵ����һ���ڵ㿪ʼ
	DLNode* cur = phead->next;
	while (cur != phead)//�����ڱ�λ��ֹͣ
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//βɾ��д��һ��
void DListPopBack1(DLNode* phead)
{
	assert(phead);//ͷ�ڵ�ĵ�ַ����Ϊ��
	assert(phead->next != phead);//���ܰ��ڱ�λ��ɾ��

	//DLNode* tail = phead->prev;
	//DLNode* tailPrev = tail->prev;

	////�����ӹ�ϵ
	//tailPrev->next = tail->next;
	//phead->prev = tailPrev;
	////ɾ�� - �����ӹ�ϵ��free���Ⱥ�˳����Ҫ��
	//free(tail);

	DListErase(phead->prev);
}

//βɾ��д�����������ٶ���һ��������Ч�������ƣ��߼��ϱ��ֲ�ֱ�ۣ������Ⱥ�˳����Ҫ��
void DListPopBack2(DLNode* phead)
{
	assert(phead);//ͷ�ڵ�ĵ�ַ����Ϊ��
	assert(phead->next != phead);//���ܰ��ڱ�λ��ɾ��

	DLNode* tail = phead->prev;
	DLNode* tailPrev = tail->prev;

	//�����ӹ�ϵ
	tail->prev->next = tail->next;
	phead->prev = tail->prev;
	
	//ɾ�� - �����ڸ������ӹ�ϵ�����free
	free(tail);
}

//ͷ��
void DListPushFront(DLNode* phead, DLTDataType x)
{
	//�ڱ�λ�ڵ��ַ����Ϊ��
	assert(phead);

	////�½ڵ�
	//DLNode* newnode = BuyListNode(x);

	////����
	//DLNode* next = phead->next;

	//phead->next = newnode;
	//newnode->prev = phead;

	//newnode->next = next;
	//next->prev = newnode;

	DListInsert(phead->next, x);
}

//ͷɾ
void DListPopFront(DLNode* phead)
{
	assert(phead);//ͷ�ڵ�ĵ�ַ����Ϊ��
	assert(phead->next != phead);//���ܰ��ڱ�λ��ɾ��

	//DLNode* next = phead->next;
	//DLNode* nextNext = next->next;

	////�����ӹ�ϵ
	//phead->next = nextNext;
	//nextNext->prev = phead;

	////ɾ��
	//free(next);

	DListErase(phead->next);
}

//����ĳ��Ԫ��
DLNode* DListFind(DLNode* phead, DLTDataType x)
{
	assert(phead);

	DLNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
			return cur;
		else
			cur = cur->next;
	}
	return NULL;
}

//ָ��λ�õĲ��� - ��posλ��֮ǰ����
void DListInsert(DLNode* pos, DLTDataType x)
{
	assert(pos);

	//�½ڵ�������
	DLNode* newnode = BuyListNode(x);
	DLNode* posPrev = pos->prev;

	posPrev->next = newnode;
	newnode->prev = posPrev;
	newnode->next = pos;
	pos->prev = newnode;
}

//ָ��λ��ɾ�� - ɾ��posָ��Ľڵ�
void DListErase(DLNode* pos)
{
	assert(pos);

	DLNode* posPrev = pos->prev;
	DLNode* posNext = pos->next;

	posPrev->next = posNext;
	posNext->prev = posPrev;

	free(pos);
}

//��������
void DListDestroy(DLNode* phead)
{
	assert(phead);
	//���ͷ��ڱ�λ����Ľڵ�
	DLNode* cur = phead->next;
	while (cur != phead)
	{
		DLNode* tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	//�ͷ��ڱ�λ�ڵ�
	free(phead);
	//ע�⣬��ʱ�����ⲿ��plist���Դ����ڱ�λ�ĵ�ַ��û�б��ÿգ�Ϊ�˱�֤�ӿڵĹ淶�ԣ���һ���ȽϺã�������֮���ֶ�����
}
//��һ�����Ƕ����������ӿڵĹ淶�ԣ�