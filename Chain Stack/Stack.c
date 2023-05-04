#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

//ջ����ؽӿ�����

//��ʼ��
void StackInit(ST** pphead);//(����û��д�ı�Ҫ��)

//�����½ڵ�
ST* BuySTNode(const STDataType x)
{
	ST* newnode = (ST*)malloc(sizeof(ST));
	if (!newnode)
	{
		printf("malloc failed\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

//��ջ(ͷ��)
void StackPush(ST** pphead, const STDataType x)
{
	//ͷָ�����Ϊ�գ�����ͷָ������ĵ�ַ����Ϊ��
	assert(pphead);

	//�½ڵ�������
	ST* newnode = BuySTNode(x);

	//ͷָ��Ϊ�� - �����пսӿ�
	//if(!(*pphead))
	if (isStackEmpty(*pphead))
	{
		*pphead = newnode;
	}
	else
	{
		newnode->next = (*pphead);
		(*pphead) = newnode;
	}
}

//��ջ��ͷɾ��
void StackPop(ST** pphead)
{
	assert(pphead);
	assert(!isStackEmpty(*pphead));//ջ�ղ�����ɾ�������пգ�

	ST* tmp = (*pphead);
	(*pphead) = (*pphead)->next;

	free(tmp);
}

//��ӡ(���øĶ�ͷָ�벻�ô�������
void StackPrint(ST* phead)//const�ؼ������Σ������޸�ָ��ָ��Ŀռ������
{
	ST* cur = phead;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//�п�(�գ�����true�� �ǿշ���false)
bool isStackEmpty(ST* phead)
{
	//ͷָ��Ϊ�վ�����
	return phead == NULL;
}

//����ջ��Ԫ��(ջ����Ϊ��)
STDataType StackTop(ST* phead)
{
	assert(!isStackEmpty(phead));

	return phead->data;
}

//����ջ����Ч���ݸ���(���η�)
//int StackSize(ST* phead)
//{
//	return phead == NULL ? 0 : StackSize(phead->next) + 1;
//}

//��ٷ�
int StackSize(ST* phead)
{
	int count = 0;
	while (phead)
	{
		count++;
		phead = phead->next;
	}
	return count;
}

//����ջ
void StackDestroy(ST** pphead)
{
	while (!isStackEmpty(*pphead))
	{
		ST* cur = *pphead;
		*pphead = (*pphead)->next;
		free(cur);
	}
}