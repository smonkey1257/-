#define _CRT_SECURE_NO_WARNINGS 1

#include "CircularQueue.h"

//声明队列节点结构体
typedef int QDataType;
typedef struct QueueNode
{
    QDataType data;
    struct QueueNode* next;
}QueueNode;

//声明队列结构体
typedef struct {
    QueueNode* head;
    QueueNode* front;//指向当前队首，频繁改变头指针会导致内存泄漏
    QueueNode* tail;
    int capacity;
} MyCircularQueue;

//递归建立队列
QueueNode* _CreateQ(int* k);

//开辟结构体
MyCircularQueue* myCircularQueueCreate(int k);

//判空：空返回真，非空返回假
bool myCircularQueueIsEmpty(MyCircularQueue* obj);

//判满：满返回真，非满返回假
bool myCircularQueueIsFull(MyCircularQueue* obj);

//递归建立队列
QueueNode* _CreateQ(int* k)
{
    if (*k == 0)
        return NULL;
    QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
    --(*k);
    if (!newnode)
    {
        printf("malloc failed\n");
        exit(-1);
    }
    newnode->next = _CreateQ(k);

    return newnode;
}

//开辟结构体
MyCircularQueue* myCircularQueueCreate(int k) {
    //k += 1;
    MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    //初始化
    QueueNode* cur = cq->head = cq->front = cq->tail = _CreateQ(&k);//头尾指针都指向第一个节点
    cq->capacity = k;
    //首尾相接
    while (cur->next)
        cur = cur->next;
    cur->next = cq->head;
    return cq;
}

// 向循环队列插入一个元素。如果成功插入则返回真。失败说明队列已满
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
        return false;

    //不满进行插入操作
    obj->tail->data = value;
    obj->tail = obj->tail->next;
    return true;
}

//从循环队列中删除一个元素。如果成功删除则返回真。失败说明队列为空
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return false;

    //非空进行删除
    obj->front = obj->front->next;
    return true;
}

//从队首获取元素。如果队列为空，返回 -1 
int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;

    //非空返回队首元素
    return obj->front->data;
}

//获取队尾元素。如果队列为空，返回 -1 
int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;

    //非空返回队尾元素（尾指针的前一个）
    QueueNode* cur = obj->front;
    while (cur->next != obj->tail)
        cur = cur->next;
    return cur->data;
}

//判空：空返回真，非空返回假
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front == obj->tail ? true : false;
}

//判满：满返回真，非满返回假
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->tail->next == obj->front ? true : false;
}

// 销毁队列（防止内存泄漏问题）
void QueueDestroy(MyCircularQueue* q)
{
    QueueNode* cur = q->head;
    while (q->capacity--)
    {
        QueueNode* tmp = cur;
        cur = cur->next;
        free(tmp);//防止内存泄露
        tmp = NULL;//可写可不写，因为变量tmp在本次循环结束后就会销毁
    }
    q->head = q->front = q->tail = NULL;
}

//销毁队列节点，再销毁队列结构体
void myCircularQueueFree(MyCircularQueue* obj) {
    QueueDestroy(obj);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/