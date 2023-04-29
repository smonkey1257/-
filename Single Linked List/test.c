#include "SList.h"


void test1()
{
	SLNode* head = NULL;
	int num = 0;
	//尾插
	SLPushBack(&head, 1);
	SLPushBack(&head, 2);
	SLPushBack(&head, 3);
	SLPrint(head);
	//头插
	//SLPushFront(&head, 1);
	//SLPushFront(&head, 2);
	//SLPushFront(&head, 3);
	//SLPrint(head);

}

void test2()
{
	SLNode* head = NULL;
	int num = 0;
	//尾插
	SLPushBack(&head, 1);
	SLPushBack(&head, 2);
	SLPushBack(&head, 3);
	SLPrint(head);
	//头插
	SLPushFront(&head, 1);
	SLPushFront(&head, 2);
	SLPushFront(&head, 3);
	SLPrint(head);

	SLPopBack(&head);
	SLPopBack(&head);
	SLPopBack(&head);
	SLPrint(head);

	SLPopFront(&head);
	SLPopFront(&head);
	SLPopFront(&head);
	SLPrint(head);

}

void test3()
{
	SLNode* head = NULL;
	//头插
	SLPushFront(&head, 1);
	SLPushFront(&head, 2);
	SLPushFront(&head, 3);
	SLPushFront(&head, 3);
	SLPushFront(&head, 3);
	SLPushFront(&head, 3);
	SLPrint(head);

	SLNode* ret = SLFind(head, 3);
	if (!ret)
	{
		printf("没找到\n");
	}
	else
	{
		int i = 1;
		printf("找到了\n");
		while (ret)
		{
			printf("第%d个ret节点：%p->%d\n", i++, ret, ret->data);
			ret = SLFind(ret->next, 3);
		}

	}
	//如果出现多个相同值如何查找？
	//找到第一个返回节点的地址，循环从下一个位置开始找
}

void test4()
{
	//查找功能可以延伸出一个修改功能
	SLNode* head = NULL;
	//头插
	SLPushFront(&head, 1);
	SLPushFront(&head, 2);
	SLPushFront(&head, 3);
	SLPushFront(&head, 3);
	SLPushFront(&head, 3);
	SLPushFront(&head, 3);
	SLPrint(head);

	SLNode* ret = SLFind(head, 3);
	if (ret)
	{
		ret->data = 30;
	}
	SLPrint(head);
	//如果想把链表中所有的3都改成30的话就从下一个节点开始找，找到就修改
}

void test5()
{
	//查找功能可以延伸出一个修改功能
	SLNode* head = NULL;
	//头插
	SLPushFront(&head, 1);
	SLPushFront(&head, 2);
	SLPushFront(&head, 3);
	SLPushFront(&head, 4);
	SLPrint(head);
	
	SLNode* ret = SLFind(head, 4);
	//SLInsert(&head, ret, 30);
	if (ret)
	{
		SLInsert(&head, ret, 30);
	}
	SLPrint(head);
	//达到类似头插入的效果
	//复用一下头插就完了
	//改好了，不能照抄，头节点前已经没有节点了，会死循环
}

void test6()
{
	SLNode* head = NULL;
	//头插
	SLPushFront(&head, 1);
	SLPushFront(&head, 2);
	SLPushFront(&head, 3);
	SLPrint(head);
	
	SLNode* ret = SLFind(head, 3);
	SLErase(&head, ret);
	SLPrint(head);

}

void test7()
{
	SLNode* head = NULL;
	//头插
	SLPushFront(&head, 1);
	SLPushFront(&head, 2);
	SLPushFront(&head, 3);
	SLPrint(head);

	SLDestory(&head);
	SLPrint(head);

}

int main(void)
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	test7();

	return 0;
}