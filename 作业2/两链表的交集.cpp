#include <iostream>

using namespace std;

typedef struct LNode {
    int data;
    struct LNode * next;
} LinkNode;

void CreateListR(LinkNode * &L, int a[], int n) {
	LinkNode * s, * r;
	L = (LinkNode *) malloc (sizeof(LinkNode));	//����ͷ���
	r = L;
	for (int i = 0; i < n; i ++) {
		s = (LinkNode *) malloc (sizeof(LinkNode));
		s->data = a[i];
		r->next = s;	//��һ���ǽ�s���뵽ͷ���(r = L)֮������ǲ��뵽r֮��
		r = s;
	}
	r->next = NULL;
} 

void DispList(LinkNode * L) {
	LinkNode * p = L->next;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void FindIntersection(LinkNode * La, LinkNode * Lb) {
    LinkNode * p = La, * q = Lb->next;      //pָLa�������ǰ�ý�㣬qָ��Lb�Ĵ�����
    while (p->next != NULL && q != NULL) {  //��La���������Lb������ʱ����ѭ��
        if (p->next->data < q->data) {  //p����һ�����ֵС��q�Ľ��ֵʱ��������ǰ�����La�Ľ��
            p->next = p->next->next;
        } else if (p->next->data > q->data){    //����ʱ��qָ��������
            q = q->next;
        } else if (p->next->data == q->data) {  //����ʱ����ָ��ͬʱ����
            p = p->next;
            q = q->next;
        }
    }
    if (p->next != NULL) {
        p->next = NULL;
    }
}

int main() {
    int a[] = {2, 4, 6, 8}, b[] = {4, 6, 8, 10};
    LinkNode * La, * Lb;
    CreateListR(La, a, 4);
    CreateListR(Lb, b, 4);
    cout << "La: ";DispList(La); 
    cout << "Lb: ";DispList(Lb);
    FindIntersection(La, Lb);
    cout << "����Ϊ��";DispList(La);
}