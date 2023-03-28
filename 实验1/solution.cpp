/*----------以下为实现solution函数的solution.cpp----------*/
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
		int cnt = 1;						//初始化cnt计数器 
		
		while (cnt % m != 0) {				//直到cnt到m时，停止计数 
			if (L1->data[num - 1] != 0) {	//data[num] != 0代表当前数未出列 
				num ++;						//移至下一个数，且cnt+1 
				cnt ++;
			}
			while(L1->data[num - 1] == 0){	//data[num] == 0代表当前数已出列 
				num ++;						//那么直接移至下一个数，且不计数，直到下一个数不为0为止 
				if (num > n) num = 1;		//如果 num 超过n的范围，就让num重新从1开始计数 
			}
			
		}

		insertElemAtTail(L2, num);			//b数组记录出列序号 
		changeElem(L1, num - 1, 0);			//出列则标记为0 
		q --;								//L1内未出列的数量-1 
		num ++;								//出列后从下一个数开始计数 
	}
	dispList(L2);
	
	destroyList(L1);
	destroyList(L2);
}
