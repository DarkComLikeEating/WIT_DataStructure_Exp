/*-------------������main.cpp��ʵ��-----------------*/
#include "SparseMatrixInTriplet.h"
#include <iostream>

using namespace std;

int main() {
    int a[5][5] = {
        {1, 2, 0, 4, 5},
        {1, 3, 5, 0, 9},
        {2, 0, 0, 0, 0},
        {0 ,0, 0, 0, 0},
        {0, 9, 7, 0, 3},
    };
    TSMatrix m;
    // ��һ����ά����a[][]��������Ԫ���ʾ
    CreateMat(m, a);
    // �����Ԫ��m
    DispTup(m);
    // ͨ����Ԫ��m�����ά����
    DispMatByTup(m);
    cout << endl;
    TSMatrix mt;
    // ת��ϡ�����,����ת�ú�Ľ����������Ԫ��mt��
    TranTat(m, mt);
    // �����Ԫ��mt
    DispTup(mt);
    // ͨ����Ԫ��mt�����λ����
    DispMatByTup(mt);
    return 0;
}