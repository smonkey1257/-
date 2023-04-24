#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

//����ջ�ṹ��
typedef struct 
{
    Queue q1;
    Queue q2;
} MyStack;

//�ں����п���һ��ջ�ṹ�壬���ҷ������ĵ�ַ
MyStack* myStackCreate() 
{
    MyStack* st = (MyStack*)malloc(sizeof(MyStack));
    //��ʼ�������е������б�
    QueueInit(&st->q1);
    QueueInit(&st->q2);
    return st;
}

//����Ϊ�յĶ��������������
void myStackPush(MyStack* obj, int x) 
{
    if (!QueueEmpty(&obj->q1))
    {
        QueuePush(&obj->q1, x);
    }
    else
    {
        QueuePush(&obj->q2, x);
    }
}

//��ת����ɾ�������Ҫ�󷵻�ջ��Ԫ��
int myStackPop(MyStack* obj) 
{
    //���ڲ�֪���ĸ�����Ϊ�գ��ȼ���
    Queue* emptyQ = &obj->q1;
    Queue* noneEmptyQ = &obj->q2;
    //������������⣬q1��Ϊ��
    if (!QueueEmpty(emptyQ))
    {
        emptyQ = &obj->q2;
        noneEmptyQ = &obj->q1;
    }

    //д��һ��
    while (QueueSize1(noneEmptyQ) > 1)
    {
        QueuePush(emptyQ, QueueFront(noneEmptyQ));
        QueuePop(noneEmptyQ);
    }

    //д�������������һ��д���ظ����ú����жϣ�����ֻ������һ��
    for (int i = QueueSize1(noneEmptyQ); i > 1; i--)
    {
        QueuePush(emptyQ, QueueFront(noneEmptyQ));
        QueuePop(noneEmptyQ);
    }

    //д������
    for (int i = QueueSize2(noneEmptyQ->head); i > 1; i--)
    {
        QueuePush(emptyQ, QueueFront(noneEmptyQ));
        QueuePop(noneEmptyQ);
    }

    //ֻʣ��һ������
    int ret = QueueFront(noneEmptyQ);
    QueuePop(noneEmptyQ);
    return ret;
}

//����ջ��Ԫ�ؼ���βԪ��
int myStackTop(MyStack* obj)
{
    return QueueEmpty(&obj->q1) ? QueueBack(&obj->q2) : QueueBack(&obj->q1);
}

//����Ҫ���������ж���Ϊ�յ�����£������
bool myStackEmpty(MyStack* obj) 
{
    return ((QueueEmpty(&obj->q1)) && (QueueEmpty(&obj->q2))) ? true : false;
}

//ջҪ���������б����١���ջ�ṹ�屻�����˲���ȫ������
void myStackFree(MyStack* obj) 
{
    //��Ϊ����һ�����в�Ϊ�գ�һ������Ϊ�յ�������������ٶ��еĺ���������˶��ԣ�����Ҫ�ж�
    if (!QueueEmpty(&obj->q1))
        QueueDestroy(&obj->q1);
    if (!QueueEmpty(&obj->q2))
        QueueDestroy(&obj->q2);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/