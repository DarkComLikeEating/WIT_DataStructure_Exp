///////////////main.cpp////////////////
#include "bst.cpp"
#include <iostream>

using namespace std;

int main() {
    BSTNode * bt;
    int path[MaxSize];
    KeyType k = 6;
    int a[] = {4, 9, 0, 1, 8, 6, 3, 5, 2, 7}, n = 10;
    cout << "(1)创建一个二叉排序树:";
    cout << endl;
    bt = CreateBST(a, n);
    cout << "(2)BST:"; DispBST(bt); cout << endl;
    cout << "(3)bt" << (JudgeBST(bt)?"是一颗BST" : "不是一颗BST") << endl;
    cout << "(4)查找" << k << "关键字(递归,顺序)"; SearchBST1(bt, k, path, -1);
    cout << "(5)查找" << k << "关键字(非递归,逆序)"; SearchBST(bt, k);
    cout << endl << "(6)删除操作:" << endl;
    cout << "原BST:"; DispBST(bt); cout << endl;
    cout << "删除节点4:";
    DeleteBST(bt, 4); DispBST(bt); cout << endl;
    cout << "删除节点5:";
    DeleteBST(bt, 5); DispBST(bt); cout << endl;
    cout << "(7)销毁BST" << endl; DestroyBST(bt);
    return 0;
}