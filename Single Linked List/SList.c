#include "SList.h"


// 动态申请一个节点
static SListNode* BuySListNode(SLTDateType x)
{
	/*
	* 为新结点开辟空间，判断是否开辟成功，是则继续，否则异常退出程序
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


// 单链表打印
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


// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	/*
	* 尾插涉及两种情况：1. 空表，即(*pplist == NULL)，需要传入二级指针；2. 非空表，需要找到尾结点 
	*/
	assert(pplist);

	if (!(*pplist))
	{
		*pplist = BuySListNode(x);
	}
	else
	{
		SListNode* tail = *pplist;
		//找尾
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = BuySListNode(x);
	}
}


// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	/*
	* 单链表头插传二级指针，涉及知识点：函数传参的传值与传址之间的区别：
	* 传值：实参 phead 为指向第一个结点的指针，如果形参为一级指针，则形参 plist 也为指向第一个结点的指针变量
	* 1. 形参只是实参的一份拷贝，改变形参链接关系无法影响phead。2. 且会在函数结束后由于局部变量被操作系统回收导致新开辟结点丢失的内存泄露问题
	* 传址：实参 &phead为指向头指针的指针，形参为二级指针pplist，解引用后可以改变phead的链接关系
	*/
	assert(pplist);

	SListNode* newnode = BuySListNode(x);
	newnode->next = (*pplist);
	*pplist = newnode;
}


// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
	/*
	* 尾删涉及三种情况：1. 空表删除；2. 只有一个结点的删除；3. 结点数大于1的删除
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


// 单链表头删
void SListPopFront(SListNode** pplist)
{
	/*
	* 头删涉及两种情况：1. 空表删除；2. 非空表删除
	*/
	assert(pplist && *pplist);

	SListNode* temp = *pplist;
	*pplist = (*pplist)->next;
	
	free(temp);
}


// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	/*
	* 查找的注意点有三：1. 空表查找；2. 找到——返回该结点指针；3. 找不到——返回NULL。
	* 注：查找不需要改动结点内容，因此不需要传二级指针
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


// 单链表修改
void SListModify(SListNode* pos, SLTDateType x)
{
	/*
	* 修改结点的内容，需要给函数传入该结点的地址
	*/
	assert(pos);

	pos->data = x;
}


// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	/*
	* pos位置之后插入只有有一种情况。
	* 在pos前插入：涉及头插，参数+1，二级指针
	*/
	assert(pos);

	SListNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}


// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos)
{
	/*
	* pos位置之后删除只有有一种情况。
	* 在pos前删除：涉及头删，参数+1，二级指针
	*/
	assert(pos);

	SListNode* temp = pos->next;
	pos->next = temp->next;
	free(temp);
}


// 单链表的销毁
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
