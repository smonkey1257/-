#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

//测试初始化和插入（完成）
void test1()
{
	//对于数组栈来说，创建一个结构体来管理（写指针写习惯了）
	ST st;
	
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);

	StackDestroy(&st);
}

//测试出栈
void test2()
{
	ST st;

	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);

	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);

	StackDestroy(&st);
}

//测试返回栈数据个数
void test3()
{
	ST st;

	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);

	printf("栈的数据个数为：%d\n", StackSize(&st));
	StackPop(&st);
	StackPop(&st);
	//测试返回栈顶元素（ok）
	printf("栈的数据个数为：%d，现在栈顶元素为：%d\n", StackSize(&st), StackTop(&st));

	StackDestroy(&st);
}

//打印出栈顺序，是否符合后进先出
void test4()
{
	ST st;

	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);

	printf("%d ", StackTop(&st));
	StackPop(&st);
	printf("%d ", StackTop(&st));
	StackPop(&st);

	StackPush(&st, 5);


	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}

	//预计输出为：4 3 5 2 1

	//实际输出：4 3 5 2 1
}

int main(void)
{
	//test1();
	//test2();
	//test3();
	test4();

	return 0;
}