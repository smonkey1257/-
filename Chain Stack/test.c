#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

void test1()
{
	ST* plist = NULL;
	//����
	StackPush(&plist, 1);
	StackPush(&plist, 2);
	StackPush(&plist, 3);
	StackPush(&plist, 4);
	//��ӡ
	StackPrint(plist);
	//��ջ
	StackPop(&plist);
	StackPop(&plist);
	StackPrint(plist);
	
	StackPop(&plist);
	StackPop(&plist);
	StackPrint(plist);

	//StackPop(&plist);//����ջΪ��ʱ��������ջ
	/*
		�����
		4->3->2->1->NULL
		2->1->NULL
		NULL
		Assertion failed: *pphead, file D:\git_work\Data-structure\Chain Stack\Stack.c, line 50
	*/
}

void test2()
{
	ST* plist = NULL;
	//����
	StackPush(&plist, 1);
	StackPush(&plist, 2);
	StackPush(&plist, 3);
	StackPush(&plist, 4);
	//��ӡ
	StackPrint(plist);

	//���Ի�ȡ�������ݸ���
	printf("%d\n", StackSize(plist));

	//���Ի�ȡջ��Ԫ��
	printf("%d\n", StackTop(plist));

	//��������ջ
	StackDestroy(&plist);
}

int main(void)
{
	//test1();
	test2();
	return 0;
}