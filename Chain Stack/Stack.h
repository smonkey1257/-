#pragma once

//常用头文件包含
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//栈节点结构体声明
typedef int STDataType;
typedef struct StackNode
{
	STDataType data;
	struct StackNode* next;
}ST;

//栈的相关接口声明

//初始化
void StackInit(ST** pphead);

//开辟新节点
ST* BuySTNode(const STDataType x);

//入栈(头插)
void StackPush(ST** pphead, const STDataType x);

//出栈（头删）
void StackPop(ST** pphead);

//打印(不用改动头指针不用传二级，const关键字保证安全性)
void StackPrint(ST* phead);

//判空
bool isStackEmpty(ST* phead);

//返回栈顶元素
STDataType StackTop(ST* phead);

//返回栈的有效数据个数
int StackSize(ST* phead);

//销毁栈
void StackDestroy(ST** pphead);