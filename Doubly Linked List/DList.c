#define _CRT_SECURE_NO_WARNINGS 1

#include "DList.h"

//初始化
/*
1. 给一个哨兵位的头节点
2. 返回头节点的地址，否则要传二级
3. prev指向自己，next也指向自己
*/
DLNode* DListInit()
{
	DLNode* phead = (DLNode*)malloc(sizeof(DLNode));
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

//多个位置要创立新节点，归并
DLNode* BuyListNode(DLTDataType x)
{
	//创建新节点
	DLNode* newnode = (DLNode*)malloc(sizeof(DLNode));
	//如果节点开辟失败，就异常退出
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

//尾插
/*
1. 不需要改动头指针，不用传二级
2. 要改动哨兵位头节点的成员，传结构体的地址
*/
void DListPushBack(DLNode* phead, DLTDataType x)
{
	assert(phead);

	////创建新节点
	//DLNode* newnode = BuyListNode(x);

	//DLNode* tail = phead->prev;
	////改链接关系
	//tail->next = newnode;
	//newnode->prev = tail;

	//newnode->next = phead;
	//phead->prev = newnode;

	DListInsert(phead, x);

}

//打印链表
void DListPrint(DLNode* phead)
{
	assert(phead);//头节点的地址不能为空
	//assert(phead->next != phead);
	
	//从哨兵位节点的下一个节点开始
	DLNode* cur = phead->next;
	while (cur != phead)//遇到哨兵位就停止
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//尾删（写法一）
void DListPopBack1(DLNode* phead)
{
	assert(phead);//头节点的地址不能为空
	assert(phead->next != phead);//不能把哨兵位给删了

	//DLNode* tail = phead->prev;
	//DLNode* tailPrev = tail->prev;

	////改链接关系
	//tailPrev->next = tail->next;
	//phead->prev = tailPrev;
	////删除 - 改链接关系与free的先后顺序无要求
	//free(tail);

	DListErase(phead->prev);
}

//尾删（写法二）（仅少定义一个变量，效率无优势，逻辑上表现不直观，代码先后顺序有要求）
void DListPopBack2(DLNode* phead)
{
	assert(phead);//头节点的地址不能为空
	assert(phead->next != phead);//不能把哨兵位给删了

	DLNode* tail = phead->prev;
	DLNode* tailPrev = tail->prev;

	//改链接关系
	tail->prev->next = tail->next;
	phead->prev = tail->prev;
	
	//删除 - 必须在改完链接关系后才能free
	free(tail);
}

//头插
void DListPushFront(DLNode* phead, DLTDataType x)
{
	//哨兵位节点地址不能为空
	assert(phead);

	////新节点
	//DLNode* newnode = BuyListNode(x);

	////链接
	//DLNode* next = phead->next;

	//phead->next = newnode;
	//newnode->prev = phead;

	//newnode->next = next;
	//next->prev = newnode;

	DListInsert(phead->next, x);
}

//头删
void DListPopFront(DLNode* phead)
{
	assert(phead);//头节点的地址不能为空
	assert(phead->next != phead);//不能把哨兵位给删了

	//DLNode* next = phead->next;
	//DLNode* nextNext = next->next;

	////改链接关系
	//phead->next = nextNext;
	//nextNext->prev = phead;

	////删除
	//free(next);

	DListErase(phead->next);
}

//查找某个元素
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

//指定位置的插入 - 在pos位置之前插入
void DListInsert(DLNode* pos, DLTDataType x)
{
	assert(pos);

	//新节点新数据
	DLNode* newnode = BuyListNode(x);
	DLNode* posPrev = pos->prev;

	posPrev->next = newnode;
	newnode->prev = posPrev;
	newnode->next = pos;
	pos->prev = newnode;
}

//指定位置删除 - 删除pos指向的节点
void DListErase(DLNode* pos)
{
	assert(pos);

	DLNode* posPrev = pos->prev;
	DLNode* posNext = pos->next;

	posPrev->next = posNext;
	posNext->prev = posPrev;

	free(pos);
}

//销毁链表
void DListDestroy(DLNode* phead)
{
	assert(phead);
	//先释放哨兵位以外的节点
	DLNode* cur = phead->next;
	while (cur != phead)
	{
		DLNode* tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	//释放哨兵位节点
	free(phead);
	//注意，此时函数外部的plist内仍存有哨兵位的地址，没有被置空，为了保证接口的规范性，传一级比较好，在销毁之后手动销毁
}
//传一级还是二级（函数接口的规范性）