/*
栈
初始化栈 InitStack(&s)
销毁栈 DestroyStack(&s)
判断栈是否为空 StackEmpty(s)
进栈 Push(&s, e)
出栈 Pop(&s, &e)
取栈顶元素 GetTop(s, &e) 
*/ 

#ifndef STACK
#define STACK

#include <iostream>
#include <malloc.h>

using namespace std;

const int Maxsize = 100;

typedef struct {
	int data[Maxsize];
	int top;
} SqStack;

void InitStack(SqStack * &s) {
	s = (SqStack * ) malloc (sizeof(SqStack));
	s->top = -1;
}

void DestroyStack(SqStack * &s) {
	free(s);
}

bool StackEmpty(SqStack * s) {
	return (s->top == -1);
}

bool Push(SqStack * &s, int e) {
	if (s->top == Maxsize - 1) {
		return false;
	}
	s->top ++;
	s->data[s->top] = e;
	return true;
}

bool Pop(SqStack * &s, int &e) {
	if (s->top == -1) {
		return false;
	}
	e = s->data[s->top];
	s->top --;
	return true;
}

bool GetTop(SqStack * &s, int &e) {
	if (s->top == -1) {
		return false;
	}
	e = s->data[s->top];
	return true;
}

#endif //STACK
