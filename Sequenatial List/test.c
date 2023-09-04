#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void testInit()//����ok
{
	SeqList sl;
	SeqListInit(&sl);
	SeqListDestroy(&sl);
}

void testInsert()
{
	SeqList sl;
	SeqListInit(&sl);

	SeqListPushBack(&sl, 1);	// ���Ե�1��β���һ�����ݣ�raalloc�䵱malloc
	SeqListPrint(&sl);

	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);	// ���Ե�2��β����INIT_NUM������
	SeqListPrint(&sl);

	SeqListPushBack(&sl, 5);	// ���Ե�3����������
	SeqListPrint(&sl);

	// ͷ��ͬ�������������Ľ��Ӱ����ԣ�������ע�͵�
	SeqListPushFront(&sl, 1);	// ���Ե�1��ͷ���һ�����ݣ�raalloc�䵱malloc
	SeqListPrint(&sl);

	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 4);	// ���Ե�2��β����INIT_NUM������
	SeqListPrint(&sl);

	SeqListPushFront(&sl, 5);	// ���Ե�3����������
	SeqListPrint(&sl);
}
//
void testDelete()//����ok
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
	SeqListPrint(&sl);		// ͷɾ����

	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPrint(&sl);		//ͷɾ�ĸ�

	SeqListPopFront(&sl);
	SeqListPrint(&sl);

	SeqListPopFront(&sl);	// ɾ�����ɾ
	SeqListPrint(&sl);
}

void testFind()//����ok
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
		printf("�ҵ��ˣ��±���%d\n", index);
	else
		printf("�Ҳ���\n");
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