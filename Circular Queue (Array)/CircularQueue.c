#define _CRT_SECURE_NO_WARNINGS 1

#include "CircularQueue.h"

//��ʵ�ֽӿڵĹ�����Ҫ��ε�������������
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k) {
    //����ѭ�����нṹ��
    MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    //�������飬����Ϊk+1
    cq->a = (int*)malloc(sizeof(int) * (k + 1));
    //��ʼ��
    cq->front = cq->tail = 0;
    cq->k = k;

    return cq;
}

//������ӣ�����ɹ������棬ʧ����ζ�Ŷ�������
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
        return false;

    obj->a[obj->tail] = value;
    ++obj->tail;
    obj->tail %= (obj->k + 1);
    return true;
}

//ɾ�����ݣ�����Ϊ��˵��ɾ��ʧ��
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return false;

    ++obj->front;
    obj->front %= (obj->k + 1);
    return true;
}

//�Ӷ��׻�ȡԪ�ء��������Ϊ�գ����� -1 
int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;

    return obj->a[obj->front];
}

//��ȡ��βԪ�ء��������Ϊ�գ����� -1 ��д��һ��
int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;

    int i = (obj->tail + obj->k) % (obj->k + 1);
    return obj->a[i];
}

//��ȡ��βԪ�ء��������Ϊ�գ����� -1 ��д������
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

//�пգ��շ���true�� �ǿշ���false
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    //��β��ͬ��ʾ��
    return obj->front == obj->tail ? true : false;
}

//������������true�� ��������false
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    //tail����һ�������front��˵��ѭ����������
    return (obj->tail + 1) % (obj->k + 1) == obj->front ? true : false;
}

//���ٶ���
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