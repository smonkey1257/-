#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

// ˳����ʼ��
void SeqListInit(SeqList* psl)
{
	assert(psl);	// �ṹ��ĵ�ַ����Ϊ��

	psl->data = NULL;
	psl->size = psl->capacity = 0;
}

// ˳�������
void SeqListDestroy(SeqList* psl)
{
	assert(psl);
	
	free(psl->data);
	psl->capacity = psl->size = 0;
}

// ���ռ䣬������ˣ���������
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

// ˳���β��
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);	// �ṹ���ַ����Ϊ��

	CheckCapacity(psl);	// �����������Ҫ�����������

	psl->data[psl->size++] = x;
}

// ˳���ͷ��
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	assert(psl);	// �ṹ���ַ����Ϊ��

	CheckCapacity(psl);	// �����������Ҫ�����������

	int i = 0;
	for (i = psl->size; i > 0; i--)	// Ų������
		psl->data[i] = psl->data[i - 1];
	
	psl->data[i] = x;
	psl->size++;
}

// ˳����ӡ
void SeqListPrint(SeqList* psl)
{
	int i = 0;
	for (i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->data[i]);
	}
	printf("\n");
}

// ˳���βɾ
void SeqListPopBack(SeqList* psl)
{
	assert(psl);	// �ṹ���ַ����Ϊ��
	assert(psl->size > 0);	// ɾ����ǰ����Ҫ��֤�����ݿ���ɾ

	psl->size--;
}


// ˳���ͷɾ
void SeqListPopFront(SeqList* psl)
{
	assert(psl);	// �ṹ���ַ����Ϊ��
	assert(psl->size > 0);	// ɾ����ǰ����Ҫ��֤�����ݿ���ɾ

	int i = 0;
	for (i = 0; i < psl->size - 1; i++)
		psl->data[i] = psl->data[i + 1];
	
	psl->size--;
}

// ˳������
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

// ˳�����posλ�ò���x
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl);
	assert(0 <= pos && pos <= psl->size);	// ȷ������λ�÷��Ϲ淶��0�ȼ���ͷ�壬psl->size�ȼ���β��

	CheckCapacity(psl);	// �����������Ҫ�����������

	int i = 0;
	for (i = psl->size; i > pos; i--)	// Ų������
		psl->data[i] = psl->data[i - 1];

	psl->data[i] = x;	// �˳�ѭ��ʱ��i����pos
	psl->size++;
}

// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* psl, size_t pos)
{
	assert(psl);
	assert(0 <= pos && pos < psl->size);	// ��ɾ�����±����䣺[0��psl->size-1]

	int i = 0;
	for (i = pos; i < psl->size - 1; i++)
		psl->data[i] = psl->data[i + 1];

	psl->size--;
}