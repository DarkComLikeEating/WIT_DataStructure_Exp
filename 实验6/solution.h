#ifndef SLN
#define SLN
#include <iostream>
#include "BinaryTree.h"
#include "SqStack.h"

using namespace std;

void PostOrder(BTNode * b) {
    SqStack * st;
    BTNode * root, * r;
    bool flag;
    InitStack(st);
    root = b;
    do {
        while (root != NULL) {
            Push(st, root);
            root = root->lchild;
        }
        r = NULL;
        flag = true;
        while (!StackEmpty(st) && flag) {
            GetTop(st, root);
            if (root->rchild == r) {
                printf("%c", root->data);
                Pop(st, root);
                r = root;
            } else {
                root = root->rchild;
                flag = false;
            }
        }
    } while (!StackEmpty(st));
    cout << endl;
    DestroyStack(st);
}


#endif // SLN