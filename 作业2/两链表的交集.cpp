#include <iostream>

using namespace std;

typedef struct LNode {
    int data;
    struct LNode * next;
} LinkNode;

void CreateListR(LinkNode * &L, int a[], int n) {
	LinkNode * s, * r;
	L = (LinkNode *) malloc (sizeof(LinkNode));	//创建头结点
	r = L;
	for (int i = 0; i < n; i ++) {
		s = (LinkNode *) malloc (sizeof(LinkNode));
		s->data = a[i];
		r->next = s;	//第一次是将s插入到头结点(r = L)之后，随后都是插入到r之后
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
    LinkNode * p = La, * q = Lb->next;      //p指La处理结点的前置结点，q指向Lb的处理结点
    while (p->next != NULL && q != NULL) {  //当La遍历完或者Lb遍历完时结束循环
        if (p->next->data < q->data) {  //p的下一个结点值小于q的结点值时，舍弃当前处理的La的结点
            p->next = p->next->next;
        } else if (p->next->data > q->data){    //大于时，q指针往后移
            q = q->next;
        } else if (p->next->data == q->data) {  //等于时，两指针同时后移
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
    cout << "交集为：";DispList(La);
}