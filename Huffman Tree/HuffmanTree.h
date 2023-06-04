#pragma once

//头文件包含
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <windows.h>

//符号声明
#define ASCII 128//主要用于统计字符和权值

//哈夫曼树结点结构体
typedef struct HFTreeNode
{
	char str;//权值对应的字符
	int weight;//权值
	int parent;//父亲
	int lchild;//左孩子
	int rchild;//右孩子
}HFTreeNode;

//哈夫曼树结构体
typedef struct HFTree
{
	HFTreeNode* data;
	int length;//记录数组长度
}HFTree;

//初始化哈夫曼树（加入字符）
HFTree* InitHFTree(int weight[], int lengthW, char* str);

//选出最小和次小
int* SelectMin(HFTree* T);

//构建哈夫曼树
void CreateHFTree(HFTree* T);

//哈夫曼编码
void HuffmanCoding(HFTree* T, int n, char** hc);

//前序遍历
void Prevoreder(HFTree* T, int root, char** hc);

//层序遍历（root是根节点的下标）
void LevelorderTraversal(HFTree* T, int root);

//解析哈夫曼编码
char* HuffmanDecoding(HFTree* T, int length, char* password);

//统计权值列表和字符列表 - 输出型参数
void StatisticalList(int** pw, char** ps, char* conversion);

//文本字符串转哈夫曼编码
char* WordTOCode(HFTree* T, int length, char* conversion, char** hc);

//存储用户输入的动态字符型顺序表
char* GetString();