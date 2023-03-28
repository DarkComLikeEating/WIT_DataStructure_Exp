/*----------����Ϊʵ��solution������solution.cpp----------*/
#include <iostream>
#include "SqList.cpp"

using namespace std;

void solution(int n, int m) {
	if (n > Maxsize) {
		cout << "n is more than Maxsize." << endl;
		return;
	}
	
	Sqlist * L1, * L2;
	initList(L1); initList(L2);
	
	for (int i = 1; i <= n; i ++) insertElemAtTail(L1, i);

	int num = 1, p = 0, q = n;
	while (q) {
		int cnt = 1;						//��ʼ��cnt������ 
		
		while (cnt % m != 0) {				//ֱ��cnt��mʱ��ֹͣ���� 
			if (L1->data[num - 1] != 0) {	//data[num] != 0����ǰ��δ���� 
				num ++;						//������һ��������cnt+1 
				cnt ++;
			}
			while(L1->data[num - 1] == 0){	//data[num] == 0����ǰ���ѳ��� 
				num ++;						//��ôֱ��������һ�������Ҳ�������ֱ����һ������Ϊ0Ϊֹ 
				if (num > n) num = 1;		//��� num ����n�ķ�Χ������num���´�1��ʼ���� 
			}
			
		}

		insertElemAtTail(L2, num);			//b�����¼������� 
		changeElem(L1, num - 1, 0);			//��������Ϊ0 
		q --;								//L1��δ���е�����-1 
		num ++;								//���к����һ������ʼ���� 
	}
	dispList(L2);
	
	destroyList(L1);
	destroyList(L2);
}
