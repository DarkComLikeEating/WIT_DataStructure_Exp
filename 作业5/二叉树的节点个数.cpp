#include <iostream>
#define ElemType char

using namespace std;
const int MaxSize = 50;
int cnt = 0;

// 二叉链中结点类型BTNode声明
typedef struct node {
    ElemType data;
    struct node * lchild;
    struct node * rchild;
} BTNode;

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

//二叉树的节点个数
void CountBTree(BTNode * b) {
    if (b != NULL) {
        cnt ++;
        printf("%c", b->data);
        if (b->lchild != NULL || b->rchild != NULL) {
            printf("(");
            CountBTree(b->lchild);
            if (b->rchild != NULL) printf(",");
            CountBTree(b->rchild);
            printf(")");
        }
    }
}

int main() {
    char str[100] = "A(B(D(,G)),C(E,F))";
    BTNode * BT;
    CreateBTree(BT, str);
    CountBTree(BT); cout << endl;
    cout << "此二叉树的节点个数为: " << cnt;
    DestoryBTree(BT);
    return 0;
}