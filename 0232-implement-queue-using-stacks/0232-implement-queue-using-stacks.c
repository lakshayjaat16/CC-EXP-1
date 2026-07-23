#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int st1[MAX_SIZE]; // Stack for incoming elements (push)
    int st2[MAX_SIZE]; // Stack for outgoing elements (pop / peek)
    int top1;
    int top2;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->top1 = -1;
    obj->top2 = -1;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->st1[++(obj->top1)] = x;
}

int myQueuePop(MyQueue* obj) {
    // If output stack is empty, transfer all elements from input stack
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->st2[++(obj->top2)] = obj->st1[(obj->top1)--];
        }
    }
    return obj->st2[(obj->top2)--];
}

int myQueuePeek(MyQueue* obj) {
    // If output stack is empty, transfer all elements from input stack
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->st2[++(obj->top2)] = obj->st1[(obj->top1)--];
        }
    }
    return obj->st2[obj->top2];
}

bool myQueueEmpty(MyQueue* obj) {
    return (obj->top1 == -1) && (obj->top2 == -1);
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}