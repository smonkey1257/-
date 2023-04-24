#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

//创建栈结构体
typedef struct 
{
    Queue q1;
    Queue q2;
} MyStack;

//在函数中开辟一个栈结构体，并且返回它的地址
MyStack* myStackCreate() 
{
    MyStack* st = (MyStack*)malloc(sizeof(MyStack));
    //初始化队列中的两个列表
    QueueInit(&st->q1);
    QueueInit(&st->q2);
    return st;
}

//往不为空的队列里面插入数据
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

//先转移再删除，最后要求返回栈顶元素
int myStackPop(MyStack* obj) 
{
    //由于不知到哪个队列为空，先假设
    Queue* emptyQ = &obj->q1;
    Queue* noneEmptyQ = &obj->q2;
    //如果假设有问题，q1不为空
    if (!QueueEmpty(emptyQ))
    {
        emptyQ = &obj->q2;
        noneEmptyQ = &obj->q1;
    }

    //写法一：
    while (QueueSize1(noneEmptyQ) > 1)
    {
        QueuePush(emptyQ, QueueFront(noneEmptyQ));
        QueuePop(noneEmptyQ);
    }

    //写法二：相较于上一种写法重复调用函数判断，这种只调用了一次
    for (int i = QueueSize1(noneEmptyQ); i > 1; i--)
    {
        QueuePush(emptyQ, QueueFront(noneEmptyQ));
        QueuePop(noneEmptyQ);
    }

    //写法三：
    for (int i = QueueSize2(noneEmptyQ->head); i > 1; i--)
    {
        QueuePush(emptyQ, QueueFront(noneEmptyQ));
        QueuePop(noneEmptyQ);
    }

    //只剩下一个数据
    int ret = QueueFront(noneEmptyQ);
    QueuePop(noneEmptyQ);
    return ret;
}

//返回栈顶元素即队尾元素
int myStackTop(MyStack* obj)
{
    return QueueEmpty(&obj->q1) ? QueueBack(&obj->q2) : QueueBack(&obj->q1);
}

//队列要在两个队列都不为空的情况下，才算空
bool myStackEmpty(MyStack* obj) 
{
    return ((QueueEmpty(&obj->q1)) && (QueueEmpty(&obj->q2))) ? true : false;
}

//栈要在两个队列被销毁、且栈结构体被销毁了才算全部销毁
void myStackFree(MyStack* obj) 
{
    //因为存在一个队列不为空，一个队列为空的情况，且在销毁队列的函数里面加了断言，必须要判断
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