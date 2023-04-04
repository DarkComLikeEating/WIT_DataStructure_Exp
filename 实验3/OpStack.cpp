/*----------以下是OpStack.cpp的实现----------*/
#ifndef OP_STACK
#define OP_STACK

#include <iostream>
#include <malloc.h>

using namespace std;

const int Maxsize = 100;

typedef struct {
	char data[Maxsize];
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

bool Push(SqStack * &s, char e) {
	if (s->top == Maxsize - 1) {
		return false;
	}
	s->top ++;
	s->data[s->top] = e;
	return true;
}

bool Pop(SqStack * &s, char &e) {
	if (s->top == -1) {
		return false;
	}
	e = s->data[s->top];
	s->top --;
	return true;
}

bool GetTop(SqStack * &s, char &e) {
	if (s->top == -1) {
		return false;
	}
	e = s->data[s->top];
	return true;
}

#endif //OP_STACK
