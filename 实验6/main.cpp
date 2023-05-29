////////////////main.cpp/////////////////
#include <iostream>
#include "BinaryTree.h"
#include "solution.h"

using namespace std;

int main() {
    BTNode * b;
    cout << "输入二叉树: ";
    char str[100] = "A(B(D(,G)),C(E,F))";
    CreateBTree(b, str);
    DispBTree(b);
    cout << endl << "二叉树的后序遍历: ";
    PostOrder(b);
    return 0;
}