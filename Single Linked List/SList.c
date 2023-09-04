#include "SList.h"


// ��̬����һ���ڵ�
static SListNode* BuySListNode(SLTDateType x)
{
	/*
	* Ϊ�½�㿪�ٿռ䣬�ж��Ƿ񿪱ٳɹ�����������������쳣�˳�����
	*/
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		printf("malloc newnode failed!\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}


// �������ӡ
void SListPrint(SListNode* plist)
{
	SListNode* cur = plist;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}


// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	/*
	* β���漰���������1. �ձ���(*pplist == NULL)����Ҫ�������ָ�룻2. �ǿձ���Ҫ�ҵ�β��� 
	*/
	assert(pplist);

	if (!(*pplist))
	{
		*pplist = BuySListNode(x);
	}
	else
	{
		SListNode* tail = *pplist;
		//��β
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = BuySListNode(x);
	}
}


// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	/*
	* ������ͷ�崫����ָ�룬�漰֪ʶ�㣺�������εĴ�ֵ�봫ַ֮�������
	* ��ֵ��ʵ�� phead Ϊָ���һ������ָ�룬����β�Ϊһ��ָ�룬���β� plist ҲΪָ���һ������ָ�����
	* 1. �β�ֻ��ʵ�ε�һ�ݿ������ı��β����ӹ�ϵ�޷�Ӱ��phead��2. �һ��ں������������ھֲ�����������ϵͳ���յ����¿��ٽ�㶪ʧ���ڴ�й¶����
	* ��ַ��ʵ�� &pheadΪָ��ͷָ���ָ�룬�β�Ϊ����ָ��pplist�������ú���Ըı�phead�����ӹ�ϵ
	*/
	assert(pplist);

	SListNode* newnode = BuySListNode(x);
	newnode->next = (*pplist);
	*pplist = newnode;
}


// �������βɾ
void SListPopBack(SListNode** pplist)
{
	/*
	* βɾ�漰���������1. �ձ�ɾ����2. ֻ��һ������ɾ����3. ���������1��ɾ��
	*/
	assert(pplist && *pplist);

	if (!(*pplist)->next)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SListNode* tail = *pplist;
		while (tail->next->next)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}


// ������ͷɾ
void SListPopFront(SListNode** pplist)
{
	/*
	* ͷɾ�漰���������1. �ձ�ɾ����2. �ǿձ�ɾ��
	*/
	assert(pplist && *pplist);

	SListNode* temp = *pplist;
	*pplist = (*pplist)->next;
	
	free(temp);
}


// ���������
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	/*
	* ���ҵ�ע���������1. �ձ���ң�2. �ҵ��������ظý��ָ�룻3. �Ҳ�����������NULL��
	* ע�����Ҳ���Ҫ�Ķ�������ݣ���˲���Ҫ������ָ��
	*/
	assert(plist);

	SListNode* dest = plist;
	while (dest)
	{
		if (dest->data == x)
			return dest;
		
		dest = dest->next;
	}
	return dest;
}


// �������޸�
void SListModify(SListNode* pos, SLTDateType x)
{
	/*
	* �޸Ľ������ݣ���Ҫ����������ý��ĵ�ַ
	*/
	assert(pos);

	pos->data = x;
}


// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	/*
	* posλ��֮�����ֻ����һ�������
	* ��posǰ���룺�漰ͷ�壬����+1������ָ��
	*/
	assert(pos);

	SListNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}


// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SListNode* pos)
{
	/*
	* posλ��֮��ɾ��ֻ����һ�������
	* ��posǰɾ�����漰ͷɾ������+1������ָ��
	*/
	assert(pos);

	SListNode* temp = pos->next;
	pos->next = temp->next;
	free(temp);
}


// �����������
void SListDestroy(SListNode* plist)
{
	assert(plist);

	while (plist)
	{
		SListNode* temp = plist;
		plist = plist->next;
		free(temp);
	}
}
