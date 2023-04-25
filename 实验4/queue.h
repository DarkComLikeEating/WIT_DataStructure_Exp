/*
队列
初始化队列 InitQueue(&q) 
销毁队列 DestroyQueue(&q)
判断队列是否为空 QueueEmpty(q)
进队列 EnQueue(&q, e)
出队列 DeQueue(&q, &e)
*/

/*----------以下是queue.h的实现----------*/
#ifndef QUEUE
#define QUEUE 

#include <iostream>
#include <malloc.h>

using namespace std;

const int Maxsize = 100;

typedef struct {
	int data[Maxsize];
	int front, rear;
} SqQueue;

void InitQueue(SqQueue * &q) {
	q = (SqQueue * ) malloc (sizeof(SqQueue));
	q->front = -1; 
	q->rear = -1;
}

void DestroyQueue(SqQueue * &q) {
	free(q);
}

bool QueueEmpty(SqQueue * q) {
	return (q->front == q->rear);
}

bool EnQueue(SqQueue * &q, int e) {
	if (q->rear == Maxsize - 1) {
		return false;
	}	
	q->rear ++;
	q->data[q->rear] = e;
	return true;
}

bool DeQueue(SqQueue * &q, int &e) {
	if (q->front == q->rear) {
		return false;
	}
	q->front ++;
	e = q->data[q->front+1];
	return true;
}

int ShowFront(SqQueue * q) {
	return q->data[q->front + 1];
}

int ShowRear(SqQueue * q) {
	return q->data[q->rear];
}

void Print(SqQueue * q) {
	int i = q->front + 1;
	while (i <= q->rear) cout << q->data[i] << " ";
}

#endif //QUEUE
