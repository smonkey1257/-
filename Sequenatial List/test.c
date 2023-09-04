#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void testInit()//——ok
{
	SeqList sl;
	SeqListInit(&sl);
	SeqListDestroy(&sl);
}

void testInsert()
{
	SeqList sl;
	SeqListInit(&sl);

	SeqListPushBack(&sl, 1);	// 测试点1：尾插第一个数据，raalloc充当malloc
	SeqListPrint(&sl);

	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);	// 测试点2：尾插满INIT_NUM个数据
	SeqListPrint(&sl);

	SeqListPushBack(&sl, 5);	// 测试点3：二倍扩容
	SeqListPrint(&sl);

	// 头插同理，如果嫌弃上面的结果影响测试，可以先注释掉
	SeqListPushFront(&sl, 1);	// 测试点1：头插第一个数据，raalloc充当malloc
	SeqListPrint(&sl);

	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 4);	// 测试点2：尾插满INIT_NUM个数据
	SeqListPrint(&sl);

	SeqListPushFront(&sl, 5);	// 测试点3：二倍扩容
	SeqListPrint(&sl);
}
//
void testDelete()//——ok
{
	SeqList sl;
	SeqListInit(&sl);

	SeqListPushFront(&sl, 1);
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 5);

	SeqListPrint(&sl);

	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPrint(&sl);		// 头删两个

	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPrint(&sl);		//头删四个

	SeqListPopFront(&sl);
	SeqListPrint(&sl);

	SeqListPopFront(&sl);	// 删完继续删
	SeqListPrint(&sl);
}

void testFind()//——ok
{
	SeqList sl;
	SeqListInit(&sl);

	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);

	SeqListPrint(&sl);

	int index = SeqListFind(&sl, 5);
	if (index != -1)
		printf("找到了，下标是%d\n", index);
	else
		printf("找不到\n");
//
	SeqListInsert(&sl, index, 3);
	SeqListPrint(&sl);

	SeqListErase(&sl, sl.size-1);
	SeqListPrint(&sl);

	SeqListDestroy(&sl);
}

int main(void)
{
	//testInit();
	//testDelete();
	//testDelete();
	testFind();
	return 0;
}