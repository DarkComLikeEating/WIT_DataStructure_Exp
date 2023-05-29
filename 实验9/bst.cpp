////////////bst.cpp////////////////
#include <iostream>
#include <malloc.h>
using namespace std;
#define MaxSize 100
typedef int KeyType;
typedef char InfoType;
typedef struct node {
    KeyType key;
    InfoType data;
    struct node * lchild, * rchild;
} BSTNode;
void DispBST(BSTNode * b);
//在二叉排序树bt中插入一个关键字为k的节点, 若插入成功返回真, 否则返回假
bool InsertBST(BSTNode * &bt, KeyType k) {
    if (bt == NULL) {
        bt = (BSTNode *) malloc (sizeof(BSTNode));
        bt->key = k;
        bt->lchild = NULL;
        bt->rchild = NULL;
        return true;
    }
    else if (k == bt->key) {
        return false;
    } else if (k < bt->key) {
        return InsertBST(bt->lchild, k);
    } else {
        return InsertBST(bt->rchild, k);
    }
}

//创建二叉排序树
BSTNode * CreateBST(KeyType A[], int n) {
    BSTNode * bt = NULL;
    int i = 0;
    while (i < n) {
        if (InsertBST(bt, A[i]) == 1) {
            printf("第%d步,插入%d:", i + 1, A[i]);
            DispBST(bt); cout << endl;
            i ++;
        }
    }
    return bt;
}

//二叉排序树的查找
int SearchBST(BSTNode * bt, KeyType k) {
    if (bt == NULL) {
        return 0;
    } else if (k == bt->key) {
        printf("%3d", bt->key);
        return 1;
    } else if (k < bt->key) {
        SearchBST(bt->lchild, k);
    } else {
        SearchBST(bt->rchild, k);
    }
    printf("%3d", bt->key);
    return 1;
}

void SearchBST1(BSTNode * bt, KeyType k, KeyType path[], int i) {
    int j;
    if (bt == NULL) {
        return ;
    } else if (k == bt->key) {
        path[i + 1] = bt->key;
        for (j = 0; j < i + 1; j ++) {
            printf("%3d", path[j]);
        }
        cout << endl;
    } else {
        path[i + 1] = bt->key;
        if (k < bt->key) {
            SearchBST1(bt->lchild, k, path, i + 1);
        } else {
            SearchBST1(bt->rchild, k, path, i + 1);
        }
    }
}

//二叉排序树的删除
void Delete1(BSTNode * p, BSTNode * &r) {
    BSTNode * q;
    if (r->rchild != NULL) {
        Delete1(p, r->rchild);
    } else {
        p->key = r->key;
        p->data = r->data;
        q = r;
        r = r->lchild;
        free(q);
    }
}

void Delete(BSTNode * &p) {
    BSTNode * q;
    if (p->rchild == NULL) {
        q = p;
        p = p->lchild;
        free(q);
    } else if (p->lchild == NULL) {
        q = p;
        p = p->rchild;
        free(q);
    } else {
        Delete1(p, p->lchild);
    }
}

bool DeleteBST(BSTNode * &bt, KeyType k) {
    if (bt == NULL) {
        return false;
    } else {
        if (k < bt->key) {
            return DeleteBST(bt->lchild, k);
        } else if (k > bt->key) {
            return DeleteBST(bt->rchild, k);
        } else {
            Delete(bt);
            return true;
        }
    }
}

//括号表示法输出二叉排序树
void DispBST(BSTNode * bt) {
    if (bt != NULL) {
        printf("%d", bt->key);
        if (bt->lchild != NULL || bt->rchild != NULL) {
            cout << "(";
            DispBST(bt->lchild);
            if (bt->rchild != NULL) cout << ",";
            DispBST(bt->rchild);
            cout << ")";
        }
    }
}

//判断bt是否为BST
KeyType predt = -32767;
bool JudgeBST(BSTNode * bt) {
    bool b1, b2;
    if (bt == NULL) {
        return true;
    } else {
        b1 = JudgeBST(bt->lchild);
        if (b1 == false || predt >= bt->key)
            return false;
        predt = bt->key;
        b2 = JudgeBST(bt->rchild);
        return b2;
    }
}

//销毁二叉排序树
void DestroyBST(BSTNode * bt) {
    if (bt != NULL) {
        DestroyBST(bt->lchild);
        DestroyBST(bt->rchild);
        free(bt);
    }
}