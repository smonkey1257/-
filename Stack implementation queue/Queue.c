#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

//����һ�����нṹ�壨������������ջ��
typedef struct {
    ST pushST;
    ST popST;
} MyQueue;

//����һ������
MyQueue* myQueueCreate() {
    //���ٶ���
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    //��ʼ��
    StackInit(&q->pushST);
    StackInit(&q->popST);
    //���ض��еĵ�ַ
    return q;
}

//���
void myQueuePush(MyQueue* obj, int x) {
    StackPush(&obj->pushST, x);
}

//�Ӷ��еĿ�ͷ�Ƴ�������Ԫ��
int myQueuePop(MyQueue* obj) {
    //�ж�popST�Ƿ�Ϊ�գ���ת��
    if (StackEmpty(&obj->popST))
    {
        while (!StackEmpty(&obj->pushST))
        {
            StackPush(&obj->popST, StackTop(&obj->pushST));
            StackPop(&obj->pushST);
        }
    }

    //��Ϊ�գ�ֱ�ӳ�����
    int front = StackTop(&obj->popST);
    StackPop(&obj->popST);
    return front;
}

//���ض��п�ͷ��Ԫ��
int myQueuePeek(MyQueue* obj) {
    //�ж�popST�Ƿ�Ϊ�գ���ת��
    if (StackEmpty(&obj->popST))
    {
        while (!StackEmpty(&obj->pushST))
        {
            StackPush(&obj->popST, StackTop(&obj->pushST));
            StackPop(&obj->pushST);
        }
    }
    //��Ϊ��ֱ�ӷ���
    return StackTop(&obj->popST);
}

//�������Ϊ�գ����� true �����򣬷��� false
bool myQueueEmpty(MyQueue* obj) {
    return ((StackEmpty(&obj->pushST)) && (StackEmpty(&obj->popST))) ? true : false;
}

//���ٶ��У�������ջ�������ٶ���
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