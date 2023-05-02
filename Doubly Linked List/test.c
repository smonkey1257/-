#define _CRT_SECURE_NO_WARNINGS 1

#include "DList.h"

//该文件针对已完成的接口进行阶段性测试

//测试初始化、尾插、打印 - （ok）
void test1()
{
	DLNode* plist = DListInit();
	DListPushBack(plist, 1);
	DListPushBack(plist, 2);
	DListPushBack(plist, 3);
	DListPushBack(plist, 4);
	DListPrint(plist);
}

//测试尾删 - （ok）
void test2()
{
	DLNode* plist = DListInit();
	DListPushBack(plist, 1);
	DListPushBack(plist, 2);
	DListPushBack(plist, 3);
	DListPushBack(plist, 4);
	DListPrint(plist);

	DListPopBack1(plist);
	DListPopBack1(plist);//先删两个
	DListPrint(plist);

	DListPopBack1(plist);
	DListPopBack1(plist);//删完
	
	//DListPopBack1(plist);//删哨兵位
	/*断言直观报错：
	Assertion failed: phead->next != phead, file D:\git_work\Data-structure\Doubly Linked List\DList.c, line 80
	*/
	DListPrint(plist);

}

//测试头插头删 - （ok）
void test3()
{
	DLNode* plist = DListInit();
	DListPushFront(plist, 1);
	DListPushFront(plist, 2);
	DListPushFront(plist, 3);
	DListPushFront(plist, 4);
	DListPrint(plist);

	DListPopFront(plist);
	DListPopFront(plist);//先删两个
	DListPrint(plist);

	/*
		4->3->2->1->NULL
		2->1->NULL
	*/
	DListPopFront(plist);
	DListPopFront(plist);//删空
	/*
		4->3->2->1->NULL
		NULL
	*/
	//DListPopFront(plist);//测试删哨兵位
	/*断言直观报错
	Assertion failed: phead->next != phead, file D:\git_work\Data-structure\Doubly Linked List\DList.c, line 132
	*/
	//打印
	DListPrint(plist);

}

//测试查找接口及其修改功能（ok）
void test4()
{
	DLNode* plist = DListInit();
	DListPushFront(plist, 1);
	DListPushFront(plist, 2);
	DListPushFront(plist, 3);
	DListPushFront(plist, 4);
	DListPrint(plist);

	//测试查找
	//DLNode* pos = DListFind(plist, 3);//(ok)
	DLNode* pos1 = DListFind(plist, 30);//(ok)
	if (pos1)
	{
		printf("找到了，该节点数据是：%d\n", pos1->data);
	}
	else
	{
		printf("链表中无此数据\n");
	}
	
	//测试修改
	DLNode* pos2 = DListFind(plist, 3);//(ok)
	pos2->data = 30;
	DListPrint(plist);

	/*	
		输出：
		4->3->2->1->NULL
		链表中无此数据
		4->30->2->1->NULL
	*/
}

//测试销毁
void test5()
{
	DLNode* plist = DListInit();
	DListPushFront(plist, 1);
	DListPushFront(plist, 2);
	DListPushFront(plist, 3);
	DListPushFront(plist, 4);
	DListPrint(plist);

	DListDestroy(plist);
	
	plist = NULL;//最后在外面手动置空
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