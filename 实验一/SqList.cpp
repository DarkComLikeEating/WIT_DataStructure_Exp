/*----------����Ϊʵ��˳��������SqList.cpp----------*/
#ifndef SqList_CPP
#define SqList_CPP

#include <iostream>
#include <malloc.h>

using namespace std;

const int Maxsize = 100;

typedef struct {
	int data[Maxsize];
	int length;
}Sqlist;

void createList(Sqlist * & L, int a[], int n) {		//����˳��� 
	int i = 0, k = 0;
	L = (Sqlist * ) malloc (sizeof(Sqlist));
	while (i < n) {
		L->data[i] = a[i];
		k ++;
		i ++;
	}
	L->length = k;
}


void initList(Sqlist * &L) {						//��ʼ��˳��� 
	L = (Sqlist * ) malloc (sizeof(Sqlist));
	L->length = 0;
}

void destroyList(Sqlist * &L) {
	free(L);
}

void dispList(Sqlist * L) {							//���˳��� 
	for (int i = 0; i < L->length; i ++) {
		cout << L->data[i] << " ";
	}
	cout << endl;
}

bool changeElem(Sqlist * &L, int i, int changednum) {	//��˳����i��Ԫ�ص�ֵ�ĳ�changednum 
	if (i < 0 || i > L->length) {
		return false;
	}
	
	L->data[i] = changednum;
	return true;
}

bool insertElemAtTail(Sqlist * &L, int e) {			//��˳���β������ֵΪe������ 
	if (L->length == Maxsize) {
		return false;
	}

	L->data[L->length] = e;
	L->length ++;
	return true;
		
}

#endif //SqList
