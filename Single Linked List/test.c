#include "SList.h"


void TestPush()
{
	SListNode* plist = NULL;		//1. ���ڱ�λͷ��㲻���ʼ����ֱ�ӽ���β��
	
	SListPrint(plist);				//���Ե�3���ձ��ӡ

	SListPushBack(&plist, 1);		//���Ե�1��β���һ�����
	SListPrint(plist);

	SListPushBack(&plist, 2);		//���Ե�2���ǿձ�β��
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);

	SListPushFront(&plist, 3);		//���Ե�4��ͷ��
	SListPushFront(&plist, 4);
	SListPrint(plist);
}

void TestPop()
{
	SListNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPrint(plist);

	//SListPopBack(&plist);			//���Ե�1�����������1��βɾ
	//SListPopBack(&plist);
	//SListPopBack(&plist);
	//SListPrint(plist);

	//SListPopBack(&plist);			//���Ե�2�����������1��βɾ
	//SListPrint(plist);
	//
	//SListPopBack(&plist);			//���Ե�3���ձ�βɾ�����Գɹ�����
	//Assertion failed: pplist && *pplist, file D:\git_work\Data-structure\Single Linked List\SList.c, line 358

	SListPopFront(&plist);			//���Ե�4���ǿձ�ͷɾ
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);

	SListPopFront(&plist);			//���Ե�5���ձ�ͷɾ�����Գɹ�����
	//Assertion failed: pplist && *pplist, file D:\git_work\Data-structure\Single Linked List\SList.c, line 388
}

void TestFind()
{
	SListNode* plist = NULL;

	//SListFind(plist, 1);			//���Ե�1���ձ���ң����Գɹ�����
	//Assertion failed: plist, file D:\git_work\Data-structure\Single Linked List\SList.c, line 404

	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPrint(plist);

	SListNode* pos = SListFind(plist, 2);//���Ե�2���Ҳ�����������NULL
	if (!pos)
	{
		printf("�Ҳ���\n");
	}
	else
	{
		printf("�ҵ��ˣ���ַ��%p\n", pos);//���Ե�3���ҵ��������ظýڵ�ĵ�ַ
		SListModify(pos, 20);			 //���Ե�4������������޸Ĺ���
		SListPrint(plist);

	}
}

void TestInsertAndErase()
{
	SListNode* plist = NULL;

	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPrint(plist);

	SListInsertAfter(SListFind(plist, 4), 40);	//���Ե�1����һ�����֮�����
	SListPrint(plist);

	SListInsertAfter(SListFind(plist, 1), 10);	//���Ե�2��β��
	SListPrint(plist);

	SListEraseAfter(SListFind(plist, 2));		//���Ե�3��ɾ��һ�����
	SListPrint(plist);
	SListEraseAfter(SListFind(plist, 3));		//���Ե�4��ɾ�������ڵĽ�㣬�����ã�Ӧ������ɾ��ָ����㣬����������ʵ��
	SListPrint(plist);

	SListDestroy(plist);
}

int main(void)
{
	//TestPush();
	//TestPop();
	//TestFind();
	//TestInsertAndErase();
	return 0;
}
