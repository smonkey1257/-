#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

void test1()
{
	ST* plist = NULL;
	//插入
	StackPush(&plist, 1);
	StackPush(&plist, 2);
	StackPush(&plist, 3);
	StackPush(&plist, 4);
	//打印
	StackPrint(plist);
	//出栈
	StackPop(&plist);
	StackPop(&plist);
	StackPrint(plist);
	
	StackPop(&plist);
	StackPop(&plist);
	StackPrint(plist);

	//StackPop(&plist);//测试栈为空时，继续出栈
	/*
		结果：
		4->3->2->1->NULL
		2->1->NULL
		NULL
		Assertion failed: *pphead, file D:\git_work\Data-structure\Chain Stack\Stack.c, line 50
	*/
}

void test2()
{
	ST* plist = NULL;
	//插入
	StackPush(&plist, 1);
	StackPush(&plist, 2);
	StackPush(&plist, 3);
	StackPush(&plist, 4);
	//打印
	StackPrint(plist);

	//测试获取链表数据个数
	printf("%d\n", StackSize(plist));

	//测试获取栈顶元素
	printf("%d\n", StackTop(plist));

	//测试销毁栈
	StackDestroy(&plist);
}

int main(void)
{
	//test1();
	test2();
	return 0;
}