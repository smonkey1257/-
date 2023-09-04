#pragma once

//头文件包含
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

///* 静态顺序表 */
//#define MAX_SIZE 1000			//顺序表最大容量
//typedef int SLDateType;			//数据类型重定义
//typedef struct SeqList			//顺序表结点结构体定义及类型重定义
//{
//	SLDateType data[MAX_SIZE];	//数组
//	int size;					//记录当前数据个数
//}SeqList;

/* 动态顺序表 */
#define INIT_NUM 4				//初始化顺序表，默认开辟INIT_NUM个空间
typedef int SLDataType;			//数据类型重定义
typedef struct SeqList			//顺序表结点结构体定义及类型重定义
{
	SLDataType* data;
	int size;
	int capacity;
}SeqList;

//顺序表基本接口
void SeqListInit(SeqList* psl);						// 顺序表初始化
void CheckCapacity(SeqList* psl);					// 检查空间，如果满了，进行增容

void SeqListPushBack(SeqList* psl, SLDataType x);	// 顺序表尾插
void SeqListPopBack(SeqList* psl);					// 顺序表尾删
void SeqListPushFront(SeqList* psl, SLDataType x);	// 顺序表头插
void SeqListPopFront(SeqList* psl);					// 顺序表头删

int SeqListFind(SeqList* psl, SLDataType x);		// 顺序表查找
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);// 顺序表在pos位置插入x
void SeqListErase(SeqList* psl, size_t pos);		// 顺序表删除pos位置的值

void SeqListDestroy(SeqList* psl);					// 顺序表销毁
void SeqListPrint(SeqList* psl);					// 顺序表打印