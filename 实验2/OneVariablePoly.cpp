/*----------以下是OneVariablePoly.cpp的实现----------*/
#include <iostream>
#include <malloc.h>

using namespace std;

const int Maxsize = 20;

typedef struct LNode {
	int coef;
	int exp;
	struct LNode * next;
} OneVarPoly;

void CreatePolyR(OneVarPoly * &P) {		//用链表尾插法的方法，创建一元多项式
	int deg = 0, co[25], flag = true;
	while (flag) {
		cout << "请输入一元多项式的最高次项的次数：" << endl;
		cin >> deg;
		if (deg > Maxsize) {			//判断输入的一元多项式是否超过程序允许的最大项数
			cout << "超出最大次数值，请重新输入。" << endl;
		} else {
			flag = false;
		}
	}
	cout << "请依次输入从第" << deg << "次项到第0次项的系数（若没有该项则输入0）：" << endl;
	for (int i = 0; i <= deg; i ++) {
		cin >> co[i];
	}
	
	OneVarPoly * s, * r;				//以下为单链表的尾插法
	P = (OneVarPoly * ) malloc (sizeof(OneVarPoly));
	r = P;
	for (int i = 0; i <= deg; i ++) {
		s = (OneVarPoly * ) malloc (sizeof(OneVarPoly));
		s->coef = co[i];
		s->exp = deg - i;
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

OneVarPoly * Add(OneVarPoly * P1, OneVarPoly * P2) {		//给出两个一元多项式，并返回相加的结果
	OneVarPoly * p, * prep,* q, * ins, * ans;				//以下为伪代码转换成算法
	if (P1->next->exp >= P2->next->exp) {
		p = P1->next, prep = P1, q = P2->next, ans = P1;
	} else {
		p = P2->next, prep = P2, q = P1->next, ans = P2;
	}

	while (p && q) {
		if (p->exp == 0) {
			p = p->next;
			prep = prep->next;
			continue;
		}
		if (q->exp == 0) {
			q = q->next;
			continue;
		}
		if (p->exp > q->exp) {
			p = p->next;
			prep = prep->next;
			continue;
		}
		if (p->exp == q->exp) {
			p->coef += q->coef;
			p = p->next;
			prep = prep->next;
			q = q->next;
			continue;
		}
		if (p->exp < q->exp) {
			ins = (OneVarPoly * ) malloc (sizeof(OneVarPoly));
			ins->coef = q->coef;
			ins->exp = q->exp;
			ins->next = p;
			prep->next = ins;

			p = p->next;
			prep = ins->next;
			q = q->next;
			continue;
		}
	} 
	while (q) {
		if (q->next == NULL) {
			prep->coef += q->coef;
			break;
		}
		ins = (OneVarPoly * ) malloc (sizeof(OneVarPoly));
		ins->coef = q->coef;
		ins->exp = q->exp;
		ins->next = p;
		prep->next = ins;

		q = q->next;
	}

	return ans;
}

void DispPoly(OneVarPoly * P) {			//输出一元多项式
	OneVarPoly * p = P->next;
	while (p != NULL) {
		if (p->exp != 0) {
			if (p->coef == 0) {
			p = p->next;
			continue;
			}
			cout << p->coef << "x^" << p->exp << " + ";
		} else {
			cout << p->coef;
		}
		p = p->next;
	}
	cout << endl;
}
