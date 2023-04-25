#pragma once

//常用头文件
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>



//数组实现栈！！！

// 下面是定长的静态栈的结构，实际中一般不实用，所以我们主要实现下面的支持动态增长的栈
//typedef int STDataType;
//#define N 10
//typedef struct Stack
//{
//	STDataType _a[N];
//	int _top; // 栈顶
//}Stack;

// 支持动态增长的栈
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top; // 栈顶
	int capacity; // 容量
}ST;

// 初始化栈
void StackInit(ST* ps);

// 销毁栈
void StackDestroy(ST* ps);

// 入栈
void StackPush(ST* ps, STDataType data);

// 出栈
void StackPop(ST* ps);

// 获取栈顶元素
STDataType StackTop(ST* ps);

// 获取栈中有效元素个数
int StackSize(ST* ps);

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
bool StackEmpty(ST* ps);