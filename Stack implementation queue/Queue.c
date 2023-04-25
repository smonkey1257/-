#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

//声明一个队列结构体（本质上是两个栈）
typedef struct {
    ST pushST;
    ST popST;
} MyQueue;

//建立一个队列
MyQueue* myQueueCreate() {
    //开辟队列
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    //初始化
    StackInit(&q->pushST);
    StackInit(&q->popST);
    //返回队列的地址
    return q;
}

//入队
void myQueuePush(MyQueue* obj, int x) {
    StackPush(&obj->pushST, x);
}

//从队列的开头移除并返回元素
int myQueuePop(MyQueue* obj) {
    //判断popST是否为空，空转移
    if (StackEmpty(&obj->popST))
    {
        while (!StackEmpty(&obj->pushST))
        {
            StackPush(&obj->popST, StackTop(&obj->pushST));
            StackPop(&obj->pushST);
        }
    }

    //不为空，直接出数据
    int front = StackTop(&obj->popST);
    StackPop(&obj->popST);
    return front;
}

//返回队列开头的元素
int myQueuePeek(MyQueue* obj) {
    //判断popST是否为空，空转移
    if (StackEmpty(&obj->popST))
    {
        while (!StackEmpty(&obj->pushST))
        {
            StackPush(&obj->popST, StackTop(&obj->pushST));
            StackPop(&obj->pushST);
        }
    }
    //不为空直接返回
    return StackTop(&obj->popST);
}

//如果队列为空，返回 true ；否则，返回 false
bool myQueueEmpty(MyQueue* obj) {
    return ((StackEmpty(&obj->pushST)) && (StackEmpty(&obj->popST))) ? true : false;
}

//销毁队列：先销毁栈，再销毁队列
void myQueueFree(MyQueue* obj) {
    StackDestroy(&obj->pushST);
    StackDestroy(&obj->popST);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/