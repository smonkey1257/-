#pragma once

//ͷ�ļ�����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <windows.h>

//��������
#define ASCII 128//��Ҫ����ͳ���ַ���Ȩֵ

//�����������ṹ��
typedef struct HFTreeNode
{
	char str;//Ȩֵ��Ӧ���ַ�
	int weight;//Ȩֵ
	int parent;//����
	int lchild;//����
	int rchild;//�Һ���
}HFTreeNode;

//���������ṹ��
typedef struct HFTree
{
	HFTreeNode* data;
	int length;//��¼���鳤��
}HFTree;

//��ʼ�����������������ַ���
HFTree* InitHFTree(int weight[], int lengthW, char* str);

//ѡ����С�ʹ�С
int* SelectMin(HFTree* T);

//������������
void CreateHFTree(HFTree* T);

//����������
void HuffmanCoding(HFTree* T, int n, char** hc);

//ǰ�����
void Prevoreder(HFTree* T, int root, char** hc);

//���������root�Ǹ��ڵ���±꣩
void LevelorderTraversal(HFTree* T, int root);

//��������������
char* HuffmanDecoding(HFTree* T, int length, char* password);

//ͳ��Ȩֵ�б���ַ��б� - ����Ͳ���
void StatisticalList(int** pw, char** ps, char* conversion);

//�ı��ַ���ת����������
char* WordTOCode(HFTree* T, int length, char* conversion, char** hc);

//�洢�û�����Ķ�̬�ַ���˳���
char* GetString();