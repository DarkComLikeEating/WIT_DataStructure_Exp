////////////////main.cpp/////////////////
#include <iostream>
#include "BinaryTree.h"
#include "solution.h"

using namespace std;

int main() {
    BTNode * b;
    cout << "���������: ";
    char str[100] = "A(B(D(,G)),C(E,F))";
    CreateBTree(b, str);
    DispBTree(b);
    cout << endl << "�������ĺ������: ";
    PostOrder(b);
    return 0;
}