///////////////main.cpp////////////////
#include "bst.cpp"
#include <iostream>

using namespace std;

int main() {
    BSTNode * bt;
    int path[MaxSize];
    KeyType k = 6;
    int a[] = {4, 9, 0, 1, 8, 6, 3, 5, 2, 7}, n = 10;
    cout << "(1)����һ������������:";
    cout << endl;
    bt = CreateBST(a, n);
    cout << "(2)BST:"; DispBST(bt); cout << endl;
    cout << "(3)bt" << (JudgeBST(bt)?"��һ��BST" : "����һ��BST") << endl;
    cout << "(4)����" << k << "�ؼ���(�ݹ�,˳��)"; SearchBST1(bt, k, path, -1);
    cout << "(5)����" << k << "�ؼ���(�ǵݹ�,����)"; SearchBST(bt, k);
    cout << endl << "(6)ɾ������:" << endl;
    cout << "ԭBST:"; DispBST(bt); cout << endl;
    cout << "ɾ���ڵ�4:";
    DeleteBST(bt, 4); DispBST(bt); cout << endl;
    cout << "ɾ���ڵ�5:";
    DeleteBST(bt, 5); DispBST(bt); cout << endl;
    cout << "(7)����BST" << endl; DestroyBST(bt);
    return 0;
}