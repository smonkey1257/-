#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

// 初始化栈
/*
* top 初始化为0， 意味着最后top是指向栈顶数据的下一个位置；数据入栈 要 先入栈，再++top。
* top 初始化为-1，意味着最后top是指向栈顶数据；数据入栈 要 先++top，再入栈。
*/
void StackInit(ST* ps)
{
	//结构体的地址不能为空
	assert(ps);

	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

// 销毁栈(内存泄露)
void StackDestroy(ST* ps)
{
	//结构体地址不能为空
	assert(ps);

	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

// 入栈
//栈这种结构类型的特点是：只允许从一端入栈，入栈的一端被称为“栈顶”
void StackPush(ST* ps, STDataType x)
{
	//传进来的结构体的地址不能为空，因此要断言
	assert(ps);

	//栈满了要考虑扩容
	if (ps->capacity == ps->top)
	{
		int NewCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		//注意realloc和malloc在参数上的不同点（在传入地址为空时，realloc可以当成malloc使用）
		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * NewCapacity);
		if (tmp == NULL)
		{
			printf("扩容失败！\n");
			exit(-1);
		}
		//扩容成功
		ps->a = tmp;
		ps->capacity = NewCapacity;
	}
	//入栈
	ps->a[ps->top] = x;
	ps->top++;
}

// 出栈
// 所谓出栈，就是让数据栈顶的数据消失，不一定是要实际删除，只要直观上看不到即可
void StackPop(ST* ps)
{
	//结构体的地址不能为空，断言
	assert(ps);

	//支持出栈的前提是栈中不为空，否则会造成数组越界，断言
	//(与其要花上大半天时间检查代码不如明确使用范围)
	assert(!StackEmpty(ps));

	ps->top--;//可以考虑演示top == -1 越界的情况
}

// 获取栈顶元素
STDataType StackTop(ST* ps)
{
/*
* top 初始化为0， 意味着最后top是指向栈顶数据的下一个位置；
* top 初始化为-1，意味着最后top是指向栈顶数据；
*/
	//本程序的top初始化为0

	//结构体地址不能为空
	assert(ps);

	//栈不能为空，为空则没有任何数据可以返回
	assert(!StackEmpty(ps));

	return ps->a[ps->top - 1];
}

// 获取栈中有效元素个数
int StackSize(ST* ps)
{
	//结构体地址不能为空
	assert(ps);

	return ps->top;
}


// 检测栈是否为空，如果为空返回true，如果不为空false 

////写法一：
//bool StackEmpty(ST* ps)
//{
//	if (ps->top == 0)
//		return true;
//	else
//		return false;
//}

////写法二：
//bool StackEmpty(ST* ps)
//{
//	return ps->top == 0 ? true : false;
//}

//写法三：（最简洁）
bool StackEmpty(ST* ps)
{
	return ps->top == 0;
}