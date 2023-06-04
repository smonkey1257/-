#define _CRT_SECURE_NO_WARNINGS 1

#include "HuffmanTree.h"

//��ʼ�����������������ַ���
HFTree* InitHFTree(int weight[], int lengthW, char* str)
{
	HFTree* T = (HFTree*)malloc(sizeof(HFTree));
	HFTreeNode* tmp = (HFTreeNode*)malloc(sizeof(HFTreeNode) * (2 * lengthW - 1));
	if (!tmp)
	{//�ж��Ƿ������Ƿ񿪱ٳɹ�
		printf("malloc failed\n");
		exit(-1);
	}
	else
	{
		T->data = tmp;
	}
	
	//��ʼ�������������ȼ��������
	T->length = lengthW;
	for (int i = 0; i < lengthW; i++)
	{
		T->data[i].str = str[i];
		T->data[i].weight = weight[i];
		T->data[i].parent = 0;//Ϊɶ����-1������Ҷ�ӽ��
		T->data[i].lchild = -1;
		T->data[i].rchild = -1;
	}

	return T;
}

//������������֮��ѡ����С�ʹ�С��
int* SelectMin(HFTree* T)
{
	unsigned int min = 0xffffffff;
	unsigned int secondMin = 0xffffffff;
	int minIndex = 0;
	int secondIndex = 0;

	//ѡ����С
	for (int i = 0; i < T->length; i++)
	{
		//����޸���
		if (T->data[i].parent == 0)
		{
			if (T->data[i].weight < min)
			{
				min = T->data[i].weight;
				minIndex = i;
			}
		}
	}
	//ѡ����С

	for (int i = 0; i < T->length; i++)
	{
		//����޸���
		if (T->data[i].parent == 0)
		{
			//��С��������С
			if (i != minIndex && T->data[i].weight < secondMin)
			{
				secondMin = T->data[i].weight;
				secondIndex = i;
			}

		}
	}
	//�������鷵������Ȩֵ���±�
	int* ret = (int*)malloc(sizeof(int) * 2);
	if (!ret)
	{//�ж��Ƿ������Ƿ񿪱ٳɹ�
		printf("malloc failed\n");
		exit(-1);
	}
	ret[0] = minIndex;
	ret[1] = secondIndex;

	return ret;
}

//������������
void CreateHFTree(HFTree* T)
{
	int* ret = NULL;
	int min = 0;
	int secondMin = 0;
	int length = T->length * 2 - 1;//���������ı߽�
	for (int i = T->length; i < length; i++)//�ڳ�ʼ��ʱ�Ѿ�������T->length��Ȩֵ
	{
		ret = SelectMin(T);
		min = ret[0];
		secondMin = ret[1];

		//�½ڵ��Ȩֵ = ��СȨֵ + ��СȨֵ
		T->data[i].parent = 0;
		T->data[i].weight = T->data[min].weight + T->data[secondMin].weight;
		//�������˺���
		T->data[i].lchild = min;
		T->data[i].rchild = secondMin;
		//��С�ʹ�С���˸���
		T->data[min].parent = i;
		T->data[secondMin].parent = i;
		//����һ��Ȩֵ
		++T->length;
	}
}

//����������
void HuffmanCoding(HFTree* T, int n, char** hc)
{
	char* cd = (char*)malloc(sizeof(char) * n);//��ʱ�Ź���������
	cd[n - 1] = '\0';//���ڵ��޸��ף��������Ϊ��

	int now = 0;   //ָ���ʱ���ڱ���Ľ��
	int parent = 0;//ָ�������ĸ��׽��
	int start = 0; //��ʱ�����ı����������д�ŵ�λ��
	int i = 0;


	//���ѭ�����ڳ�ʼ����������Ҫ����Ľ��
	while (i < n)
	{
		//printf("%d, ", i);
		start = (int)(n - 1);//������Զ��ָ��λ�ÿ�ʼ���
		now = i;  //����while���ƽ�����������Ҳ�ڸ���
		parent = T->data[now].parent;//���׽���ʼ��Ϊnow���ĸ���
		
		//�ڲ�ѭ�����ڻ�ȡָ�����ı���
		while (parent != 0)
		{
			start--;

			if (T->data[parent].lchild == now)		//������丸�׽�������������Ϊ0����Ϊ1
			{
				cd[start] = '0';
			}
			else
			{
				cd[start] = '1';
			}

			now = parent;							//��ʱ�Ľ��Ϊԭ���ĸ��׽��
			parent = T->data[now].parent;			//���¸��׽��
		}

		//printf("%s\n", &cd[start]);
		hc[i] = (char*)malloc((n - start) * sizeof(char));	//���ٴ�ű����������ڴ�
		strcpy(hc[i], &cd[start]);				//��ָ�븴�Ʊ���
		i++;
	}
}

//��������������
char* HuffmanDecoding(HFTree* T, int length, char* password)
{
	//�洢����
	char* store = NULL;
	int size = 0, capacity = 0, newcapacity = 0;

	int len = (int)strlen(password);//��ȡ�û�������볤��
	int node = T->length - 1;  //�Ӹ��ڵ����(�����±�)

	for (int i = 0; i < len; i++)
	{
		//����
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

		//����Ϊ'0'�������
		if (password[i] == '0')
		{
			node = T->data[node].lchild;
			//���½��֮���жϸýڵ��Ƿ���Ҷ�ӽ��
			if (T->data[node].lchild == -1 && T->data[node].rchild == -1)
			{
				store[size++] = T->data[node].str;
				node = T->length - 1;
			}
		}
		//����Ϊ'1'�����ұ�
		else
		{
			node = T->data[node].rchild;
			//���½��֮���жϸýڵ��Ƿ���Ҷ�ӽ��
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

//ǰ�����
void Prevoreder(HFTree* T, int root, char** hc)
{
	if (root != -1)
	{
		if (T->data[root].lchild == -1 && T->data[root].rchild == -1)
			printf("%c:%s\n", T->data[root].str, hc[root]);//�������
			//printf("%c:%d\n", T->data[root].str, T->data[root].weight);//�����

		Prevoreder(T, T->data[root].lchild, hc);
		Prevoreder(T, T->data[root].rchild, hc);
	}
}

//���������root�Ǹ��ڵ���±꣩
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
			queue[rear++] = T->data[tmp].lchild;//���Ӳ�Ϊ�գ��������
		if (T->data[tmp].rchild != -1)
			queue[rear++] = T->data[tmp].rchild;//�Һ��Ӳ�Ϊ�գ��Һ������
	}
}

//ͳ��Ȩֵ�б���ַ��б� - ����Ͳ���(�Ľ�)
void StatisticalList(int** pw, char** ps, char* conversion)
{
	int A[ASCII] = { 0 };//��;��ͳ��
	for (int i = 0; conversion[i]; i++)//ͳ��
	{
		A[conversion[i]]++;
	}


	char* str = (char*)malloc(sizeof(char) * ASCII);//��ȡ�ַ��б�
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


	int* weight = (int*)malloc(sizeof(int) * (int)strlen(str));//��ȡȨֵ�б�
	for (int i = 0; i < (int)strlen(str); i++)
	{
		weight[i] = A[str[i]];
	}

	*pw = weight;
	*ps = str;
}

//�ı��ַ���ת����������
char* WordTOCode(HFTree* T, int length, char* conversion, char** hc)
{
	char* store = NULL;
	int size = 0, capacity = 0, newcapacity = 0;

	int l = 0;

	int count = 0;
	int lenC = (int)strlen(conversion);
	for (int i = 0; i < lenC; i++)//�ı��ַ�����ÿ���ַ���Ҫ����ɱ���
	{
		for (int j = 0; j < length; j++)//һ��ת����ʱ�����ַ��б����Ӧ�ұ���
		{

			if (conversion[i] == T->data[j].str)
			{
				int _len = (int)strlen(hc[j]);//�����ַ��ı���ĳ���
				//����
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
				//��ʹ��strcat���������׷��
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

//�洢�û�����Ķ�̬�ַ���˳���
char* GetString()
{
	char* str = NULL;
	int capacity = 0;//�������
	int size = 0;//��ǰ����
	char input = 0;//�����ַ�

	int i = 0;
	while ((input = getchar()) != '\n')
	{
		//����
		if (size == capacity)
		{
			int newcapacity = (capacity == 0 ? 4 : capacity * 2);
			str = (char*)realloc(str, sizeof(char) * newcapacity);
			capacity = newcapacity;//������������
			if (!str)
			{
				printf("realloc failed\n");
				exit(-1);
			}
		}
		//���ݴ洢������
		str[i] = input;
		size++;
		i++;
	}
	str[i] = '\0';
	return str;
}