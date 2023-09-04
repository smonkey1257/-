#include "SList.h"


void TestPush()
{
	SListNode* plist = NULL;		//1. 无哨兵位头结点不需初始化，直接进行尾插
	
	SListPrint(plist);				//测试点3：空表打印

	SListPushBack(&plist, 1);		//测试点1：尾插第一个结点
	SListPrint(plist);

	SListPushBack(&plist, 2);		//测试点2：非空表尾插
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);

	SListPushFront(&plist, 3);		//测试点4：头插
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

	//SListPopBack(&plist);			//测试点1：结点数大于1的尾删
	//SListPopBack(&plist);
	//SListPopBack(&plist);
	//SListPrint(plist);

	//SListPopBack(&plist);			//测试点2：结点数等于1的尾删
	//SListPrint(plist);
	//
	//SListPopBack(&plist);			//测试点3：空表尾删（断言成功！）
	//Assertion failed: pplist && *pplist, file D:\git_work\Data-structure\Single Linked List\SList.c, line 358

	SListPopFront(&plist);			//测试点4：非空表头删
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);

	SListPopFront(&plist);			//测试点5：空表头删（断言成功！）
	//Assertion failed: pplist && *pplist, file D:\git_work\Data-structure\Single Linked List\SList.c, line 388
}

void TestFind()
{
	SListNode* plist = NULL;

	//SListFind(plist, 1);			//测试点1：空表查找（断言成功！）
	//Assertion failed: plist, file D:\git_work\Data-structure\Single Linked List\SList.c, line 404

	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPrint(plist);

	SListNode* pos = SListFind(plist, 2);//测试点2：找不到——返回NULL
	if (!pos)
	{
		printf("找不到\n");
	}
	else
	{
		printf("找到了，地址是%p\n", pos);//测试点3：找到——返回该节点的地址
		SListModify(pos, 20);			 //测试点4：查找延申的修改功能
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

	SListInsertAfter(SListFind(plist, 4), 40);	//测试点1：第一个结点之后插入
	SListPrint(plist);

	SListInsertAfter(SListFind(plist, 1), 10);	//测试点2：尾插
	SListPrint(plist);

	SListEraseAfter(SListFind(plist, 2));		//测试点3：删除一个结点
	SListPrint(plist);
	SListEraseAfter(SListFind(plist, 3));		//测试点4：删除不存在的结点，不好用，应该做到删除指定结点，单向链表不好实现
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
