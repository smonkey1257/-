#define _CRT_SECURE_NO_WARNINGS 1

#include "CircularQueue.h"

//在实现接口的过程中要多次调用这两个函数
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k) {
    //开辟循环队列结构体
    MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    //开辟数组，长度为k+1
    cq->a = (int*)malloc(sizeof(int) * (k + 1));
    //初始化
    cq->front = cq->tail = 0;
    cq->k = k;

    return cq;
}

//数据入队，插入成功返回真，失败意味着队列已满
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
        return false;

    obj->a[obj->tail] = value;
    ++obj->tail;
    obj->tail %= (obj->k + 1);
    return true;
}

//删除数据，队列为空说明删除失败
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return false;

    ++obj->front;
    obj->front %= (obj->k + 1);
    return true;
}

//从队首获取元素。如果队列为空，返回 -1 
int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;

    return obj->a[obj->front];
}

//获取队尾元素。如果队列为空，返回 -1 （写法一）
int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;

    int i = (obj->tail + obj->k) % (obj->k + 1);
    return obj->a[i];
}

//获取队尾元素。如果队列为空，返回 -1 （写法二）
int myCircularQueueRear1(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    /*
        if(obj->tail == 0)
        {
            return obj->a[k];
        }
        else
        {
            return obj->a[tail-1];
        }
    */
    return obj->tail == 0 ? obj->a[obj->k] : obj->a[obj->tail - 1];
}

//判空：空返回true， 非空返回false
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    //首尾相同表示空
    return obj->front == obj->tail ? true : false;
}

//判满：满返回true， 非满返回false
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    //tail的下一个如果是front，说明循环队列已满
    return (obj->tail + 1) % (obj->k + 1) == obj->front ? true : false;
}

//销毁队列
void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->a);
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