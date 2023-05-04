#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

//栈的相关接口声明

//初始化
void StackInit(ST** pphead);//(好像没有写的必要？)

//开辟新节点
ST* BuySTNode(const STDataType x)
{
	ST* newnode = (ST*)malloc(sizeof(ST));
	if (!newnode)
	{
		printf("malloc failed\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

//入栈(头插)
void StackPush(ST** pphead, const STDataType x)
{
	//头指针可以为空，但是头指针变量的地址不能为空
	assert(pphead);

	//新节点新数据
	ST* newnode = BuySTNode(x);

	//头指针为空 - 改用判空接口
	//if(!(*pphead))
	if (isStackEmpty(*pphead))
	{
		*pphead = newnode;
	}
	else
	{
		newnode->next = (*pphead);
		(*pphead) = newnode;
	}
}

//出栈（头删）
void StackPop(ST** pphead)
{
	assert(pphead);
	assert(!isStackEmpty(*pphead));//栈空不能再删（复用判空）

	ST* tmp = (*pphead);
	(*pphead) = (*pphead)->next;

	free(tmp);
}

//打印(不用改动头指针不用传二级）
void StackPrint(ST* phead)//const关键字修饰，不能修改指针指向的空间的内容
{
	ST* cur = phead;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//判空(空，返回true， 非空返回false)
bool isStackEmpty(ST* phead)
{
	//头指针为空就算真
	return phead == NULL;
}

//返回栈顶元素(栈不能为空)
STDataType StackTop(ST* phead)
{
	assert(!isStackEmpty(phead));

	return phead->data;
}

//返回栈的有效数据个数(分治法)
//int StackSize(ST* phead)
//{
//	return phead == NULL ? 0 : StackSize(phead->next) + 1;
//}

//穷举法
int StackSize(ST* phead)
{
	int count = 0;
	while (phead)
	{
		count++;
		phead = phead->next;
	}
	return count;
}

//销毁栈
void StackDestroy(ST** pphead)
{
	while (!isStackEmpty(*pphead))
	{
		ST* cur = *pphead;
		*pphead = (*pphead)->next;
		free(cur);
	}
}