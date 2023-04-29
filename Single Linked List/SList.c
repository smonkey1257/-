#include "SList.h"

// 单链表打印
void SLPrint(SLNode* plist)
{
	//空链表也要打印，不用断言

	//在不为空指针之前
	while (plist)
	{
		printf("%d->", plist->data);
		plist = plist->next;
	}
	//最后提示空指针并且换行
	printf("NULL\n");
}
//不需要改动链表，因此不需要二级指针



// 单链表尾插
//一、遍历链表直到最后一个节点，尾节点链接新节点（这里）
//二、通过维护一个尾指针，直接用尾指针链接新节点——以后再改吧，现在不研究了（3.21）

void SLPushBack(SLNode** pphead, SLDataType x)
{
	assert(pphead);//头指针的地址不能为空要断言

	//一上来就先建一个新的节点，用来存放传进来的参数
	if (!(*pphead))
	{
		//头指针为空
		*pphead = BuySListNode(x);
	}
	else
	{
		SLNode* newnode = BuySListNode(x);
		//找到链表的尾节点，把newnode变成新的尾节点
		SLNode* tail = *pphead;
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}


//在头插为空或者尾插为空是都要建立一个新的节点，干脆把这部分归并为一个函数，简便代码
// 申请一个节点
SLNode* BuySListNode(SLDataType x)
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	if (!(newnode))
	{
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	
	return newnode;
}



// 单链表的头插
void SLPushFront(SLNode** pphead, SLDataType x)
{
	assert(pphead);//头指针的地址不能为空要断言

	if (!(*pphead))
	{
		//头指针为空
		*pphead = BuySListNode(x);
	}
	else
	{
		//头指针不为空
		SLNode* newnode = BuySListNode(x);
		
		//头插
		newnode->next = *pphead;
		*pphead = newnode;
	}
}
//如果为空就建一个新节点给它
//tmp = newnode;仅仅只是一份拷贝来的，把变量newnode储存的地址给tmp的话，出了函数就会销毁，



// 单链表的尾删

void SLPopBack(SLNode** pphead)
{
	//头指针不能为空，为空就没有内容可以删
	assert(*pphead);
	
	SLNode* tail = *pphead;
	SLNode* prev = NULL;//指向tail的前一个节点
	
	//链表长度 = 1
	if (tail->next == NULL)
	{
		free(tail);
		*pphead = NULL;
	}
	else
	{//链表长度 > 1
		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
}

void SLPopBack1(SLNode** pphead)
{
	//头指针不能为空，为空就没有内容可以删
	assert(*pphead);

	SLNode* tail = *pphead;
	//只剩一个节点了
	if (tail->next == NULL)
	{
		free(tail);
		*pphead = NULL;
	}
	else
	{
		while (tail->next->next)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}



// 单链表头删 

void SLPopFront(SLNode** pphead)
{
	assert(pphead);//头指针的地址不能为空要断言
	assert(*pphead);//头指针不能为空，为空就没有内容可以删

	SLNode* tmp = *pphead;

	*pphead = (*pphead)->next;
	free(tmp);
	tmp = NULL;
}

//函数要改变头指针，就要传头指针的地址，函数参数用二级指针接收
//	head = head->next;只是改掉了头指针的拷贝，head出了函数就会被销毁



// 单链表查找

SLNode* SLFind(SLNode* pphead, SLDataType x)
{
	while (pphead)
	{
		if (pphead->data == x)
		{
			return pphead;
		}
		else
		{
			pphead = pphead->next;
		}
	}
	return NULL;
}

//plist->next作为循环条件意思就是跳过第一个节点，然而当个只有一个时，会出现有但返回NULL的情况，因此要从头指针开开始
//查找也是不用传二级指针的，因为不用改动
//找到了就返回该节点的地址,找不到就返回NULL



// 单链表在pos位置之前插入x
// pos来自于Find 
void SLInsert(SLNode** pphead, SLNode* pos, SLDataType x)
{
	assert(pphead);//头指针的地址不能为空要断言

	SLNode* cur = *pphead;
	SLNode* newnode = BuySListNode(x);
	if ((*pphead)->data == pos->data)
	{
		//头插
		newnode->next = (*pphead);
		*pphead = newnode;
	}
	else
	{
		while (cur->next != pos)
		{
			cur = cur->next;
		}

		cur->next = newnode;
		newnode->next = pos;
	}
}
//涉及头插问题，所以要传二级指针



// 单链表在pos位置之后插入x
void SLInsertAfter(SLNode* pos, SLDataType x)
{
	assert(pos);
	SLNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
//pos之后插入的话，就算pos指向第一个节点，也不用担心改变头节点了，因此不需要传二级指针了
//甚至不需要传链表的头指针了



// 单链表删除pos位置的值
void SLErase(SLNode** pphead, SLNode* pos)
{
	assert(pphead);//头指针的地址不能为空要断言

	if (*pphead == pos)
	{
		//pos指向第二个节点，涉及头删，传二级
		SLPopFront(pphead);
	}
	else
	{
		//pos指向第三个及第三个节点之后的节点，无特殊情况
		SLNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
	}
}
//pos 出函数就销毁，没有置空的必要

// 单链表删除pos位置之后的值
void SLEraseAfter(SLNode* pos)
{
	assert(pos->next);//当链表有一个节点时不适合再用这个功能
	
	SLNode* next = pos->next;
	pos->next = next->next;
	free(next);
}

//清空链表 - 释放所有节点
void SLDestory(SLNode** pphead)
{
	assert(pphead);//头指针的地址不能为空要断言

	while (*pphead)
	{
		SLNode* tmp = *pphead;

		*pphead = (*pphead)->next;

		free(tmp);
	}
	*pphead = NULL;
}