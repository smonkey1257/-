#define _CRT_SECURE_NO_WARNINGS 1

//自定义头文件包含
#include "HuffmanTree.h"

//要求二：根据指定的字符列表和权值列表输入每个字符的哈夫曼编码
void function1()
{
	//要求的权值列表
	int weight[] = { 186, 64, 13, 22, 32, 103, 21, 15, 47,
					57,   1,  5, 32, 20,  57, 63, 15,  1,
					48,  51, 80, 23,  8,  18,  1, 16,  1
				   };
	//要求的字符列表
	char* str = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	int length = (int)strlen(str);//字符列表的长度（和权值列表的长度相同）

	//VS不支持变长数组，用动态内存开辟处理char* hc[length + 1]
	char** hc = (char**)malloc(sizeof(char*) * length);//存放哈夫曼编码列表

	//------------初始化哈夫曼树-----------------
	HFTree* T = InitHFTree(weight, length, str);


	//------------构建哈夫曼树-------------------
	CreateHFTree(T);


	//------------哈夫曼编码---------------------
	HuffmanCoding(T, length, hc);


	//------------前序遍历输出----------------
	Prevoreder(T, T->length - 1, hc);


	//------------销毁哈夫曼树----------------
	for (int i = 0; i < length; i++)
	{
		free(hc[i]);
	}
	free(hc);
	free(T->data);
	free(T);
}

//要求三：将指定的文本字符串转换为哈夫曼编码
void function2()
{
	int* weight = NULL;//权值列表
	char* str = NULL;//字符列表

	//指定文本字符串
	char* conversion = "THIS PROGRAM IS MY FAVORITE";

	//统计文本字符串并生成字符列表和权值列表
	StatisticalList(&weight, &str, conversion);

	int length = (int)strlen(str);//权值列表的长度由字符列表的长度决定，且二者相同

	char** hc = (char**)malloc(sizeof(char*) * length);//存放哈夫曼编码


	//------------初始化哈夫曼树-----------------
	HFTree* T = InitHFTree(weight, length, str);


	//------------构建哈夫曼树------------------
	CreateHFTree(T);


	//------------构建哈夫曼哈夫曼编码--------------------
	HuffmanCoding(T, length, hc);


	//文本字符串转哈夫曼编码
	printf("哈夫曼编码为：\n");
	char* ret = WordTOCode(T, length, conversion, hc);
	printf("%s\n哈夫曼编码长度为：%d\n", ret, (int)strlen(ret));


	//------------销毁哈夫曼树----------------
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

//要求四：将一段哈夫曼编码转换为文本
void function3()
{
	int* weight = NULL;//权值列表
	char* str = NULL;//字符列表

	//指定文本字符串
	char* conversion = "THIS PROGRAM IS MY FAVORITE";

	//统计文本字符串并生成字符列表和权值列表
	StatisticalList(&weight, &str, conversion);

	int length = (int)strlen(str);//权值列表的长度由字符列表的长度决定，且二者相同

	char** hc = (char**)malloc(sizeof(char*) * length);//存放哈夫曼编码


	//------------初始化哈夫曼树-----------------
	HFTree* T = InitHFTree(weight, length, str);


	//------------构建哈夫曼树------------------
	CreateHFTree(T);


	//------------构建哈夫曼哈夫曼编码--------------------
	HuffmanCoding(T, length, hc);


	//文本字符串转哈夫曼编码
	char* ret = WordTOCode(T, length, conversion, hc);
	printf("待解编码为：\n%s", ret);

	//解哈夫曼编码
	printf("\n解码后的文本为：");
	char* password = ret;
	char* text = HuffmanDecoding(T, length, password);
	if (strcmp(text, conversion) == 0)
		printf("%s\n", text);
	else
		printf("解码失败\n");

	//------------销毁哈夫曼树----------------
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
	printf("即将展示要求二");
	for (int i = 0; i < 3; i++)
	{
		printf(". ");
		Sleep(1000);
	}
	system("cls");
	printf("要求二结果如下：\n");
	function1();


	Sleep(5000);
	system("cls");
	printf("即将展示要求三");
	for (int i = 0; i < 3; i++)
	{
		printf(". ");
		Sleep(1000);
	}
	system("cls");
	printf("要求三结果如下：\n");
	function2();


	Sleep(5000);
	system("cls");
	printf("即将展示要求四");
	for (int i = 0; i < 3; i++)
	{
		printf(". ");
		Sleep(1000);
	}
	system("cls");
	printf("要求四结果如下：\n");
	function3();

	return 0;
}