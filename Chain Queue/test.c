#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

//测试初始化跟入队（插入） - 成功
void test1()
{
	//写指针写习惯了，这是一个结构体！！！
	Queue q;

	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
}

////测试初始化跟出队（头删)
void test2()
{
	Queue q;

	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	//测试当队伍为空时再进行删除，此时对空指针进行free，出问题
	QueuePop(&q);
}

//测试获取队列头部元素、尾部元素、获取队列元素个数的两种方法
void test3()
{
	Queue q;

	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	//打印头部元素 - 预计输出：1; 实际输出：1。（链表不为空）(过)
	printf("%d\n", QueueFront(&q));

	//打印头部元素 - 预计输出：5; 实际输出：5。（链表不为空）（过）
	printf("%d\n", QueueBack(&q));

	//打印队列中元素个数 - 预计输出：5；实际输出：5。（）链表不为空且累计输出（过）
	printf("%d\n", QueueSize2(q.head));
}

void test4()
{
	Queue q;

	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	QueueDestroy(&q);
}

int main(void)
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}