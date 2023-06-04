#define _CRT_SECURE_NO_WARNINGS 1

//�Զ���ͷ�ļ�����
#include "HuffmanTree.h"

//Ҫ���������ָ�����ַ��б��Ȩֵ�б�����ÿ���ַ��Ĺ���������
void function1()
{
	//Ҫ���Ȩֵ�б�
	int weight[] = { 186, 64, 13, 22, 32, 103, 21, 15, 47,
					57,   1,  5, 32, 20,  57, 63, 15,  1,
					48,  51, 80, 23,  8,  18,  1, 16,  1
				   };
	//Ҫ����ַ��б�
	char* str = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	int length = (int)strlen(str);//�ַ��б�ĳ��ȣ���Ȩֵ�б�ĳ�����ͬ��

	//VS��֧�ֱ䳤���飬�ö�̬�ڴ濪�ٴ���char* hc[length + 1]
	char** hc = (char**)malloc(sizeof(char*) * length);//��Ź����������б�

	//------------��ʼ����������-----------------
	HFTree* T = InitHFTree(weight, length, str);


	//------------������������-------------------
	CreateHFTree(T);


	//------------����������---------------------
	HuffmanCoding(T, length, hc);


	//------------ǰ��������----------------
	Prevoreder(T, T->length - 1, hc);


	//------------���ٹ�������----------------
	for (int i = 0; i < length; i++)
	{
		free(hc[i]);
	}
	free(hc);
	free(T->data);
	free(T);
}

//Ҫ��������ָ�����ı��ַ���ת��Ϊ����������
void function2()
{
	int* weight = NULL;//Ȩֵ�б�
	char* str = NULL;//�ַ��б�

	//ָ���ı��ַ���
	char* conversion = "THIS PROGRAM IS MY FAVORITE";

	//ͳ���ı��ַ����������ַ��б��Ȩֵ�б�
	StatisticalList(&weight, &str, conversion);

	int length = (int)strlen(str);//Ȩֵ�б�ĳ������ַ��б�ĳ��Ⱦ������Ҷ�����ͬ

	char** hc = (char**)malloc(sizeof(char*) * length);//��Ź���������


	//------------��ʼ����������-----------------
	HFTree* T = InitHFTree(weight, length, str);


	//------------������������------------------
	CreateHFTree(T);


	//------------��������������������--------------------
	HuffmanCoding(T, length, hc);


	//�ı��ַ���ת����������
	printf("����������Ϊ��\n");
	char* ret = WordTOCode(T, length, conversion, hc);
	printf("%s\n���������볤��Ϊ��%d\n", ret, (int)strlen(ret));


	//------------���ٹ�������----------------
	free(str);
	free(weight);
	for (int i = 0; i < length; i++)
	{
		free(hc[i]);
	}
	free(hc);
	free(ret);
	free(T->data);
	free(T);
}

//Ҫ���ģ���һ�ι���������ת��Ϊ�ı�
void function3()
{
	int* weight = NULL;//Ȩֵ�б�
	char* str = NULL;//�ַ��б�

	//ָ���ı��ַ���
	char* conversion = "THIS PROGRAM IS MY FAVORITE";

	//ͳ���ı��ַ����������ַ��б��Ȩֵ�б�
	StatisticalList(&weight, &str, conversion);

	int length = (int)strlen(str);//Ȩֵ�б�ĳ������ַ��б�ĳ��Ⱦ������Ҷ�����ͬ

	char** hc = (char**)malloc(sizeof(char*) * length);//��Ź���������


	//------------��ʼ����������-----------------
	HFTree* T = InitHFTree(weight, length, str);


	//------------������������------------------
	CreateHFTree(T);


	//------------��������������������--------------------
	HuffmanCoding(T, length, hc);


	//�ı��ַ���ת����������
	char* ret = WordTOCode(T, length, conversion, hc);
	printf("�������Ϊ��\n%s", ret);

	//�����������
	printf("\n�������ı�Ϊ��");
	char* password = ret;
	char* text = HuffmanDecoding(T, length, password);
	if (strcmp(text, conversion) == 0)
		printf("%s\n", text);
	else
		printf("����ʧ��\n");

	//------------���ٹ�������----------------
	free(str);
	free(weight);
	for (int i = 0; i < length; i++)
	{
		free(hc[i]);
	}
	free(hc);
	free(ret);
	free(text);
	free(T->data);
	free(T);
}

int main(void)
{
	printf("����չʾҪ���");
	for (int i = 0; i < 3; i++)
	{
		printf(". ");
		Sleep(1000);
	}
	system("cls");
	printf("Ҫ���������£�\n");
	function1();


	Sleep(5000);
	system("cls");
	printf("����չʾҪ����");
	for (int i = 0; i < 3; i++)
	{
		printf(". ");
		Sleep(1000);
	}
	system("cls");
	printf("Ҫ����������£�\n");
	function2();


	Sleep(5000);
	system("cls");
	printf("����չʾҪ����");
	for (int i = 0; i < 3; i++)
	{
		printf(". ");
		Sleep(1000);
	}
	system("cls");
	printf("Ҫ���Ľ�����£�\n");
	function3();

	return 0;
}