#include <iostream>
#define ElemType int

using namespace std;
const int MaxSize = 50;

// 二叉链中结点类型BTNode声明
typedef struct node {
    ElemType data;
    struct node * lchild;
    struct node * rchild;
} BTNode;

// 队列数据结构的声明和操作
typedef struct {
	BTNode * data[MaxSize];
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

bool EnQueue(SqQueue * &q, BTNode * e) {
	if (q->rear == MaxSize - 1) {
		return false;
	}	
	q->rear ++;
	q->data[q->rear] = e;
	return true;
}

bool DeQueue(SqQueue * &q, BTNode * &e) {
	if (q->front == q->rear) {
		return false;
	}
	q->front ++;
	e = q->data[q->front];
	return true;
}

//创建二叉树
void CreateBTree(BTNode * &b, char * str) {
    BTNode * St[MaxSize], * p;
    int top = -1, k, j = 0;
    char ch;
    b = NULL;
    ch = str[j];
    while (ch != '\0') {
        switch(ch) {
            case '(': 
                top ++;
                St[top] = p;
                k = 1;
                break;
            case ')':
                top --;
                break;
            case ',':
                k = 2;
                break;
            default:
                p = (BTNode * ) malloc (sizeof(BTNode));
                p->data = ch;
                p->lchild = NULL;
                p->rchild = NULL;
                if(b == NULL) {
                    b = p;
                } else {
                    switch(k) {
                        case 1:
                            St[top]->lchild = p;
                            break;
                        case 2:
                            St[top]->rchild = p;
                            break;
                    }
                }
        }
        j ++;
        ch = str[j];
    }
}

//销毁二叉树
void DestoryBTree(BTNode * &b) {
    if (b != NULL) {
        DestoryBTree(b->lchild);
        DestoryBTree(b->rchild);
        free(b);
    }
}

//层次遍历算法
void LevelOrder(BTNode * b) {
    BTNode * p;
    SqQueue * qu;
    InitQueue(qu);
    EnQueue(qu, b);
    while (!QueueEmpty(qu)) {
        DeQueue(qu, p);
        printf("%c", p->data);
        if (p->lchild != NULL) {
            EnQueue(qu, p->lchild);
        } 
        if (p->rchild != NULL) {
            EnQueue(qu, p->rchild);
        }
    }
}

//输出二叉树
void DispBTree(BTNode * b) {
    if (b != NULL) {
        printf("%c", b->data);
        if (b->lchild != NULL || b->rchild != NULL) {
            printf("(");
            DispBTree(b->lchild);
            if (b->rchild != NULL) printf(",");
            DispBTree(b->rchild);
            printf(")");
        }
    }
}

int main() {
    char str[100] = "A(B(D(,G)),C(E,F))";
    BTNode * BT;
    CreateBTree(BT, str);
    cout << "树: ";
    DispBTree(BT);
    cout << "的层次遍历结果如下:\n";
    LevelOrder(BT);
    DestoryBTree(BT);
    return 0;
}
