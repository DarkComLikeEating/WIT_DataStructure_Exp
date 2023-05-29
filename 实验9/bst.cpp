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
//�ڶ���������bt�в���һ���ؼ���Ϊk�Ľڵ�, ������ɹ�������, ���򷵻ؼ�
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

//��������������
BSTNode * CreateBST(KeyType A[], int n) {
    BSTNode * bt = NULL;
    int i = 0;
    while (i < n) {
        if (InsertBST(bt, A[i]) == 1) {
            printf("��%d��,����%d:", i + 1, A[i]);
            DispBST(bt); cout << endl;
            i ++;
        }
    }
    return bt;
}

//�����������Ĳ���
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

//������������ɾ��
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

//���ű�ʾ���������������
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

//�ж�bt�Ƿ�ΪBST
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

//���ٶ���������
void DestroyBST(BSTNode * bt) {
    if (bt != NULL) {
        DestroyBST(bt->lchild);
        DestroyBST(bt->rchild);
        free(bt);
    }
}