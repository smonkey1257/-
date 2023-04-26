#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

//���Գ�ʼ������ӣ����룩 - �ɹ�
void test1()
{
	//дָ��дϰ���ˣ�����һ���ṹ�壡����
	Queue q;

	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
}

////���Գ�ʼ�������ӣ�ͷɾ)
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
	//���Ե�����Ϊ��ʱ�ٽ���ɾ������ʱ�Կ�ָ�����free��������
	QueuePop(&q);
}

//���Ի�ȡ����ͷ��Ԫ�ء�β��Ԫ�ء���ȡ����Ԫ�ظ��������ַ���
void test3()
{
	Queue q;

	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	//��ӡͷ��Ԫ�� - Ԥ�������1; ʵ�������1��������Ϊ�գ�(��)
	printf("%d\n", QueueFront(&q));

	//��ӡͷ��Ԫ�� - Ԥ�������5; ʵ�������5��������Ϊ�գ�������
	printf("%d\n", QueueBack(&q));

	//��ӡ������Ԫ�ظ��� - Ԥ�������5��ʵ�������5����������Ϊ�����ۼ����������
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