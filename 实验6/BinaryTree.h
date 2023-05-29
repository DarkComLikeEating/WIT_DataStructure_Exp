#ifndef BT
#define BT

#include <iostream>
#define ElemType char

using namespace std;
const int MaxSize = 50;

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

//查找节点
BTNode * FindNode(BTNode * b, ElemType x) {
    BTNode * p;
    if (b == NULL) {
        return NULL;
    } else if (b->data == x) {
        return b;
    } else {
        p = FindNode(b->lchild, x);
        if (p != NULL) {
            return p;
        } else {
            return FindNode(b->rchild, x);
        }
    }
}

//找孩子结点
BTNode * LchildNode(BTNode * p) {
    return p->lchild;
}
BTNode * rchildNode(BTNode * p) {
    return p->rchild;
}

//求高度
int BTHeight(BTNode * b) {
    int lchildh, rchildh;
    if (b == NULL) {
        return 0;
    } else {
        lchildh = BTHeight(b->lchild);
        rchildh = BTHeight(b->rchild);
        return (lchildh > rchildh) ? (lchildh + 1) : (rchildh + 1);
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

#endif //BT