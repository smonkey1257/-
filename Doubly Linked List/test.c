#define _CRT_SECURE_NO_WARNINGS 1

#include "DList.h"

//���ļ��������ɵĽӿڽ��н׶��Բ���

//���Գ�ʼ����β�塢��ӡ - ��ok��
void test1()
{
	DLNode* plist = DListInit();
	DListPushBack(plist, 1);
	DListPushBack(plist, 2);
	DListPushBack(plist, 3);
	DListPushBack(plist, 4);
	DListPrint(plist);
}

//����βɾ - ��ok��
void test2()
{
	DLNode* plist = DListInit();
	DListPushBack(plist, 1);
	DListPushBack(plist, 2);
	DListPushBack(plist, 3);
	DListPushBack(plist, 4);
	DListPrint(plist);

	DListPopBack1(plist);
	DListPopBack1(plist);//��ɾ����
	DListPrint(plist);

	DListPopBack1(plist);
	DListPopBack1(plist);//ɾ��
	
	//DListPopBack1(plist);//ɾ�ڱ�λ
	/*����ֱ�۱���
	Assertion failed: phead->next != phead, file D:\git_work\Data-structure\Doubly Linked List\DList.c, line 80
	*/
	DListPrint(plist);

}

//����ͷ��ͷɾ - ��ok��
void test3()
{
	DLNode* plist = DListInit();
	DListPushFront(plist, 1);
	DListPushFront(plist, 2);
	DListPushFront(plist, 3);
	DListPushFront(plist, 4);
	DListPrint(plist);

	DListPopFront(plist);
	DListPopFront(plist);//��ɾ����
	DListPrint(plist);

	/*
		4->3->2->1->NULL
		2->1->NULL
	*/
	DListPopFront(plist);
	DListPopFront(plist);//ɾ��
	/*
		4->3->2->1->NULL
		NULL
	*/
	//DListPopFront(plist);//����ɾ�ڱ�λ
	/*����ֱ�۱���
	Assertion failed: phead->next != phead, file D:\git_work\Data-structure\Doubly Linked List\DList.c, line 132
	*/
	//��ӡ
	DListPrint(plist);

}

//���Բ��ҽӿڼ����޸Ĺ��ܣ�ok��
void test4()
{
	DLNode* plist = DListInit();
	DListPushFront(plist, 1);
	DListPushFront(plist, 2);
	DListPushFront(plist, 3);
	DListPushFront(plist, 4);
	DListPrint(plist);

	//���Բ���
	//DLNode* pos = DListFind(plist, 3);//(ok)
	DLNode* pos1 = DListFind(plist, 30);//(ok)
	if (pos1)
	{
		printf("�ҵ��ˣ��ýڵ������ǣ�%d\n", pos1->data);
	}
	else
	{
		printf("�������޴�����\n");
	}
	
	//�����޸�
	DLNode* pos2 = DListFind(plist, 3);//(ok)
	pos2->data = 30;
	DListPrint(plist);

	/*	
		�����
		4->3->2->1->NULL
		�������޴�����
		4->30->2->1->NULL
	*/
}

//��������
void test5()
{
	DLNode* plist = DListInit();
	DListPushFront(plist, 1);
	DListPushFront(plist, 2);
	DListPushFront(plist, 3);
	DListPushFront(plist, 4);
	DListPrint(plist);

	DListDestroy(plist);
	
	plist = NULL;//����������ֶ��ÿ�
}

int main(void)
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
	return 0;
}