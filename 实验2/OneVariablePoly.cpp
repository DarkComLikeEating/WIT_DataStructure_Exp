/*----------������OneVariablePoly.cpp��ʵ��----------*/
#include <iostream>
#include <malloc.h>

using namespace std;

const int Maxsize = 20;

typedef struct LNode {
	int coef;
	int exp;
	struct LNode * next;
} OneVarPoly;

void CreatePolyR(OneVarPoly * &P) {		//������β�巨�ķ���������һԪ����ʽ
	int deg = 0, co[25], flag = true;
	while (flag) {
		cout << "������һԪ����ʽ����ߴ���Ĵ�����" << endl;
		cin >> deg;
		if (deg > Maxsize) {			//�ж������һԪ����ʽ�Ƿ񳬹�����������������
			cout << "����������ֵ�����������롣" << endl;
		} else {
			flag = false;
		}
	}
	cout << "����������ӵ�" << deg << "�����0�����ϵ������û�и���������0����" << endl;
	for (int i = 0; i <= deg; i ++) {
		cin >> co[i];
	}
	
	OneVarPoly * s, * r;				//����Ϊ�������β�巨
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

OneVarPoly * Add(OneVarPoly * P1, OneVarPoly * P2) {		//��������һԪ����ʽ����������ӵĽ��
	OneVarPoly * p, * prep,* q, * ins, * ans;				//����Ϊα����ת�����㷨
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

void DispPoly(OneVarPoly * P) {			//���һԪ����ʽ
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
