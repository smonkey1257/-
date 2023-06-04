#define _CRT_SECURE_NO_WARNINGS 1

#include "HuffmanTree.h"

//初始化哈夫曼树（加入字符）
HFTree* InitHFTree(int weight[], int lengthW, char* str)
{
	HFTree* T = (HFTree*)malloc(sizeof(HFTree));
	HFTreeNode* tmp = (HFTreeNode*)malloc(sizeof(HFTreeNode) * (2 * lengthW - 1));
	if (!tmp)
	{//判断是否数组是否开辟成功
		printf("malloc failed\n");
		exit(-1);
	}
	else
	{
		T->data = tmp;
	}
	
	//初始化哈夫曼树长度及结点数据
	T->length = lengthW;
	for (int i = 0; i < lengthW; i++)
	{
		T->data[i].str = str[i];
		T->data[i].weight = weight[i];
		T->data[i].parent = 0;//为啥不是-1？区分叶子结点
		T->data[i].lchild = -1;
		T->data[i].rchild = -1;
	}

	return T;
}

//构建哈夫曼树之（选出最小和次小）
int* SelectMin(HFTree* T)
{
	unsigned int min = 0xffffffff;
	unsigned int secondMin = 0xffffffff;
	int minIndex = 0;
	int secondIndex = 0;

	//选出最小
	for (int i = 0; i < T->length; i++)
	{
		//结点无父亲
		if (T->data[i].parent == 0)
		{
			if (T->data[i].weight < min)
			{
				min = T->data[i].weight;
				minIndex = i;
			}
		}
	}
	//选出次小

	for (int i = 0; i < T->length; i++)
	{
		//结点无父亲
		if (T->data[i].parent == 0)
		{
			//次小不能是最小
			if (i != minIndex && T->data[i].weight < secondMin)
			{
				secondMin = T->data[i].weight;
				secondIndex = i;
			}

		}
	}
	//利用数组返回两个权值的下标
	int* ret = (int*)malloc(sizeof(int) * 2);
	if (!ret)
	{//判断是否数组是否开辟成功
		printf("malloc failed\n");
		exit(-1);
	}
	ret[0] = minIndex;
	ret[1] = secondIndex;

	return ret;
}

//构建哈夫曼树
void CreateHFTree(HFTree* T)
{
	int* ret = NULL;
	int min = 0;
	int secondMin = 0;
	int length = T->length * 2 - 1;//哈夫曼树的边界
	for (int i = T->length; i < length; i++)//在初始化时已经输入了T->length个权值
	{
		ret = SelectMin(T);
		min = ret[0];
		secondMin = ret[1];

		//新节点的权值 = 最小权值 + 次小权值
		T->data[i].parent = 0;
		T->data[i].weight = T->data[min].weight + T->data[secondMin].weight;
		//父亲有了孩子
		T->data[i].lchild = min;
		T->data[i].rchild = secondMin;
		//最小和次小有了父亲
		T->data[min].parent = i;
		T->data[secondMin].parent = i;
		//多了一个权值
		++T->length;
	}
}

//哈夫曼编码
void HuffmanCoding(HFTree* T, int n, char** hc)
{
	char* cd = (char*)malloc(sizeof(char) * n);//临时放哈夫曼编码
	cd[n - 1] = '\0';//根节点无父亲，自身编码为空

	int now = 0;   //指向此时正在编码的结点
	int parent = 0;//指向编码结点的父亲结点
	int start = 0; //此时产生的编码在数组中存放的位置
	int i = 0;


	//外层循环用于初始化，更换需要编码的结点
	while (i < n)
	{
		//printf("%d, ", i);
		start = (int)(n - 1);//编码永远从指定位置开始存放
		now = i;  //随着while的推进，编码的起点也在更换
		parent = T->data[now].parent;//父亲结点初始化为now结点的父亲
		
		//内层循环用于获取指定结点的编码
		while (parent != 0)
		{
			start--;

			if (T->data[parent].lchild == now)		//结点是其父亲结点的左子树编码为0，右为1
			{
				cd[start] = '0';
			}
			else
			{
				cd[start] = '1';
			}

			now = parent;							//此时的结点为原来的父亲结点
			parent = T->data[now].parent;			//更新父亲结点
		}

		//printf("%s\n", &cd[start]);
		hc[i] = (char*)malloc((n - start) * sizeof(char));	//开辟存放编码的数组的内存
		strcpy(hc[i], &cd[start]);				//传指针复制编码
		i++;
	}
}

//解析哈夫曼编码
char* HuffmanDecoding(HFTree* T, int length, char* password)
{
	//存储译文
	char* store = NULL;
	int size = 0, capacity = 0, newcapacity = 0;

	int len = (int)strlen(password);//获取用户输入编码长度
	int node = T->length - 1;  //从根节点出发(根的下标)

	for (int i = 0; i < len; i++)
	{
		//扩容
		if (size == capacity)
		{
			newcapacity = capacity == 0 ? 10 : capacity * 2;
			store = (char*)realloc(store, newcapacity);
			capacity = newcapacity;
			if (!store)
			{
				printf("realloc failed\n");
				exit(-1);
			}
		}

		//编码为'0'，走左边
		if (password[i] == '0')
		{
			node = T->data[node].lchild;
			//更新结点之后判断该节点是否是叶子结点
			if (T->data[node].lchild == -1 && T->data[node].rchild == -1)
			{
				store[size++] = T->data[node].str;
				node = T->length - 1;
			}
		}
		//编码为'1'，走右边
		else
		{
			node = T->data[node].rchild;
			//更新结点之后判断该节点是否是叶子结点
			if (T->data[node].lchild == -1 && T->data[node].rchild == -1)
			{
				store[size++] = T->data[node].str;
				node = T->length - 1;
			}
		}
	}
	store[size] = '\0';
	return store;
}

//前序遍历
void Prevoreder(HFTree* T, int root, char** hc)
{
	if (root != -1)
	{
		if (T->data[root].lchild == -1 && T->data[root].rchild == -1)
			printf("%c:%s\n", T->data[root].str, hc[root]);//输出编码
			//printf("%c:%d\n", T->data[root].str, T->data[root].weight);//简单输出

		Prevoreder(T, T->data[root].lchild, hc);
		Prevoreder(T, T->data[root].rchild, hc);
	}
}

//层序遍历（root是根节点的下标）
void LevelorderTraversal(HFTree* T, int root)
{
	int* queue = (int*)malloc(sizeof(int) * (2 * T->length));
	int head = 0, rear = 0;
	int tmp = 0;


	queue[rear++] = root;
	while (head != rear)
	{
		tmp = queue[head++];
		printf(" %d", T->data[tmp].weight);

		if (T->data[tmp].lchild != -1)
			queue[rear++] = T->data[tmp].lchild;//左孩子不为空，左孩子入队
		if (T->data[tmp].rchild != -1)
			queue[rear++] = T->data[tmp].rchild;//右孩子不为空，右孩子入队
	}
}

//统计权值列表和字符列表 - 输出型参数(改进)
void StatisticalList(int** pw, char** ps, char* conversion)
{
	int A[ASCII] = { 0 };//用途：统计
	for (int i = 0; conversion[i]; i++)//统计
	{
		A[conversion[i]]++;
	}


	char* str = (char*)malloc(sizeof(char) * ASCII);//提取字符列表
	int i = 0, size = 0;
	while (i < ASCII)
	{
		if (A[i] != 0)
		{
			str[size++] = i;
		}
		i++;
	}
	str[size] = '\0';


	int* weight = (int*)malloc(sizeof(int) * (int)strlen(str));//提取权值列表
	for (int i = 0; i < (int)strlen(str); i++)
	{
		weight[i] = A[str[i]];
	}

	*pw = weight;
	*ps = str;
}

//文本字符串转哈夫曼编码
char* WordTOCode(HFTree* T, int length, char* conversion, char** hc)
{
	char* store = NULL;
	int size = 0, capacity = 0, newcapacity = 0;

	int l = 0;

	int count = 0;
	int lenC = (int)strlen(conversion);
	for (int i = 0; i < lenC; i++)//文本字符串的每个字符都要翻译成编码
	{
		for (int j = 0; j < length; j++)//一趟转编码时，在字符列表里对应找编码
		{

			if (conversion[i] == T->data[j].str)
			{
				int _len = (int)strlen(hc[j]);//单个字符的编码的长度
				//扩容
				if (size + _len >= capacity)
				{
					newcapacity = capacity == 0 ? 10 : capacity * 2;
					store = (char*)realloc(store, newcapacity);
					capacity = newcapacity;
					if (!store)
					{
						printf("realloc failed\n");
						exit(-1);
					}
				}
				//不使用strcat，改用逐个追加
				for (l = 0; hc[j][l]; l++)
				{
					store[size++] = hc[j][l];
				}

				count += (int)strlen(hc[j]);
			}
		}
	}
	store[size] = '\0';
	return store;
}

//存储用户输入的动态字符型顺序表
char* GetString()
{
	char* str = NULL;
	int capacity = 0;//最大容量
	int size = 0;//当前个数
	char input = 0;//输入字符

	int i = 0;
	while ((input = getchar()) != '\n')
	{
		//扩容
		if (size == capacity)
		{
			int newcapacity = (capacity == 0 ? 4 : capacity * 2);
			str = (char*)realloc(str, sizeof(char) * newcapacity);
			capacity = newcapacity;//更新数组容量
			if (!str)
			{
				printf("realloc failed\n");
				exit(-1);
			}
		}
		//数据存储进数组
		str[i] = input;
		size++;
		i++;
	}
	str[i] = '\0';
	return str;
}