#pragma once

//ͷ�ļ�����
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

///* ��̬˳��� */
//#define MAX_SIZE 1000			//˳����������
//typedef int SLDateType;			//���������ض���
//typedef struct SeqList			//˳�����ṹ�嶨�弰�����ض���
//{
//	SLDateType data[MAX_SIZE];	//����
//	int size;					//��¼��ǰ���ݸ���
//}SeqList;

/* ��̬˳��� */
#define INIT_NUM 4				//��ʼ��˳���Ĭ�Ͽ���INIT_NUM���ռ�
typedef int SLDataType;			//���������ض���
typedef struct SeqList			//˳�����ṹ�嶨�弰�����ض���
{
	SLDataType* data;
	int size;
	int capacity;
}SeqList;

//˳�������ӿ�
void SeqListInit(SeqList* psl);						// ˳����ʼ��
void CheckCapacity(SeqList* psl);					// ���ռ䣬������ˣ���������

void SeqListPushBack(SeqList* psl, SLDataType x);	// ˳���β��
void SeqListPopBack(SeqList* psl);					// ˳���βɾ
void SeqListPushFront(SeqList* psl, SLDataType x);	// ˳���ͷ��
void SeqListPopFront(SeqList* psl);					// ˳���ͷɾ

int SeqListFind(SeqList* psl, SLDataType x);		// ˳������
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);// ˳�����posλ�ò���x
void SeqListErase(SeqList* psl, size_t pos);		// ˳���ɾ��posλ�õ�ֵ

void SeqListDestroy(SeqList* psl);					// ˳�������
void SeqListPrint(SeqList* psl);					// ˳����ӡ