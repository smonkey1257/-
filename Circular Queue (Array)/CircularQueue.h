#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct {
    int* a;
    int front;
    int tail;
    int k;//��Ч�洢���ݸ���
} MyCircularQueue;
