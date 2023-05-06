#define _CRT_SECURE_NO_WARNINGS 1

#include "CircularQueue.h"

//�������нڵ�ṹ��
typedef int QDataType;
typedef struct QueueNode
{
    QDataType data;
    struct QueueNode* next;
}QueueNode;

//�������нṹ��
typedef struct {
    QueueNode* head;
    QueueNode* front;//ָ��ǰ���ף�Ƶ���ı�ͷָ��ᵼ���ڴ�й©
    QueueNode* tail;
    int capacity;
} MyCircularQueue;

//�ݹ齨������
QueueNode* _CreateQ(int* k);

//���ٽṹ��
MyCircularQueue* myCircularQueueCreate(int k);

//�пգ��շ����棬�ǿշ��ؼ�
bool myCircularQueueIsEmpty(MyCircularQueue* obj);

//�������������棬�������ؼ�
bool myCircularQueueIsFull(MyCircularQueue* obj);

//�ݹ齨������
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

//���ٽṹ��
MyCircularQueue* myCircularQueueCreate(int k) {
    //k += 1;
    MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    //��ʼ��
    QueueNode* cur = cq->head = cq->front = cq->tail = _CreateQ(&k);//ͷβָ�붼ָ���һ���ڵ�
    cq->capacity = k;
    //��β���
    while (cur->next)
        cur = cur->next;
    cur->next = cq->head;
    return cq;
}

// ��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻��档ʧ��˵����������
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
        return false;

    //�������в������
    obj->tail->data = value;
    obj->tail = obj->tail->next;
    return true;
}

//��ѭ��������ɾ��һ��Ԫ�ء�����ɹ�ɾ���򷵻��档ʧ��˵������Ϊ��
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return false;

    //�ǿս���ɾ��
    obj->front = obj->front->next;
    return true;
}

//�Ӷ��׻�ȡԪ�ء��������Ϊ�գ����� -1 
int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;

    //�ǿշ��ض���Ԫ��
    return obj->front->data;
}

//��ȡ��βԪ�ء��������Ϊ�գ����� -1 
int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;

    //�ǿշ��ض�βԪ�أ�βָ���ǰһ����
    QueueNode* cur = obj->front;
    while (cur->next != obj->tail)
        cur = cur->next;
    return cur->data;
}

//�пգ��շ����棬�ǿշ��ؼ�
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front == obj->tail ? true : false;
}

//�������������棬�������ؼ�
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->tail->next == obj->front ? true : false;
}

// ���ٶ��У���ֹ�ڴ�й©���⣩
void QueueDestroy(MyCircularQueue* q)
{
    QueueNode* cur = q->head;
    while (q->capacity--)
    {
        QueueNode* tmp = cur;
        cur = cur->next;
        free(tmp);//��ֹ�ڴ�й¶
        tmp = NULL;//��д�ɲ�д����Ϊ����tmp�ڱ���ѭ��������ͻ�����
    }
    q->head = q->front = q->tail = NULL;
}

//���ٶ��нڵ㣬�����ٶ��нṹ��
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