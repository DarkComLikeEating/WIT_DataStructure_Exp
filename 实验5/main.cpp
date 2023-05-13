/*-------------以下是main.cpp的实现-----------------*/
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
    // 从一个二维矩阵a[][]创建其三元组表示
    CreateMat(m, a);
    // 输出三元组m
    DispTup(m);
    // 通过三元组m输出二维矩阵
    DispMatByTup(m);
    cout << endl;
    TSMatrix mt;
    // 转置稀疏矩阵,并将转置后的结果保存在三元组mt中
    TranTat(m, mt);
    // 输出三元组mt
    DispTup(mt);
    // 通过三元组mt输出二位矩阵
    DispMatByTup(mt);
    return 0;
}