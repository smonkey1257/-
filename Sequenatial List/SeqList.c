#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

// 顺序表初始化
void SeqListInit(SeqList* psl)
{
	assert(psl);	// 结构体的地址不能为空

	psl->data = NULL;
	psl->size = psl->capacity = 0;
}

// 顺序表销毁
void SeqListDestroy(SeqList* psl)
{
	assert(psl);
	
	free(psl->data);
	psl->capacity = psl->size = 0;
}

// 检查空间，如果满了，进行增容
static void CheckCapacity(SeqList* psl)
{
	if (psl->capacity <= psl->size)
	{
		int NewCapacity = psl->capacity == 0 ? INIT_NUM : psl->capacity * 2;
		SLDataType* tmp = realloc(psl->data, NewCapacity * sizeof(SLDataType));
		if (!tmp)
		{
			printf("realloc failed!\n");
			exit(-1);
		}
		psl->data = tmp;
		psl->capacity = NewCapacity;
	}
}

// 顺序表尾插
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);	// 结构体地址不能为空

	CheckCapacity(psl);	// 检测容量，需要的情况下扩容

	psl->data[psl->size++] = x;
}

// 顺序表头插
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	assert(psl);	// 结构体地址不能为空

	CheckCapacity(psl);	// 检测容量，需要的情况下扩容

	int i = 0;
	for (i = psl->size; i > 0; i--)	// 挪动数据
		psl->data[i] = psl->data[i - 1];
	
	psl->data[i] = x;
	psl->size++;
}

// 顺序表打印
void SeqListPrint(SeqList* psl)
{
	int i = 0;
	for (i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->data[i]);
	}
	printf("\n");
}

// 顺序表尾删
void SeqListPopBack(SeqList* psl)
{
	assert(psl);	// 结构体地址不能为空
	assert(psl->size > 0);	// 删除的前提是要保证有数据可以删

	psl->size--;
}


// 顺序表头删
void SeqListPopFront(SeqList* psl)
{
	assert(psl);	// 结构体地址不能为空
	assert(psl->size > 0);	// 删除的前提是要保证有数据可以删

	int i = 0;
	for (i = 0; i < psl->size - 1; i++)
		psl->data[i] = psl->data[i + 1];
	
	psl->size--;
}

// 顺序表查找
int SeqListFind(SeqList* psl, SLDataType x)
{
	assert(psl);

	int i = 0; 
	for (i = 0; i < psl->size; i++)
	{
		if (psl->data[i] == x)
			return i;
	}

	return -1;
}

// 顺序表在pos位置插入x
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl);
	assert(0 <= pos && pos <= psl->size);	// 确保插入位置符合规范，0等价于头插，psl->size等价于尾插

	CheckCapacity(psl);	// 检测容量，需要的情况下扩容

	int i = 0;
	for (i = psl->size; i > pos; i--)	// 挪动数据
		psl->data[i] = psl->data[i - 1];

	psl->data[i] = x;	// 退出循环时，i就是pos
	psl->size++;
}

// 顺序表删除pos位置的值
void SeqListErase(SeqList* psl, size_t pos)
{
	assert(psl);
	assert(0 <= pos && pos < psl->size);	// 可删除的下标区间：[0，psl->size-1]

	int i = 0;
	for (i = pos; i < psl->size - 1; i++)
		psl->data[i] = psl->data[i + 1];

	psl->size--;
}