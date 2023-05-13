/*---------------以下是SparseMatrixInTriplet.h的实现---------------*/
#ifndef TRIPLET
#define TRIPLET

#include <iostream>

using namespace std;

const int M = 5; //rows of sparse matrix
const int N = 5; //cols of sparse matrix
const int Maxsize = 25; //max size of nonzero element in sparse matrix

typedef struct {
    int r;
    int c;
    int d;
} TupNode;

typedef struct {
    int rows;
    int cols;
    int nums;
    TupNode data[Maxsize];
} TSMatrix;

//从一个二位稀疏矩阵创建其三元组表示
void CreateMat(TSMatrix &t, int A[M][N]) {
    t.rows = M; t.cols = N; t.nums = 0;
    for (int i = 0; i < M; i ++) {
        for (int j = 0; j < N; j ++) {
            if (A[i][j] != 0) {
                t.data[t.nums].r = i;
                t.data[t.nums].c = j;
                t.data[t.nums].d = A[i][j];
                t.nums ++;
            }
        }
    }
}

//三元组元素的赋值
bool Value(TSMatrix &t, int x, int i, int j) {
    int k = 0, k1;
    if (i >= t.rows || j >= t.cols) {
        return false;
    }
    while (k < t.nums && i > t.data[k].r) k ++;
    while (k < t.nums && i == t.data[k].r && j > t.data[k].c) k ++;
    if (t.data[k].r == i && t.data[k].c == j) {
        t.data[k].d = x;
    } else {
        for (k1 = t.nums - 1; k1 >= k; k1 --) {
            t.data[k1 + 1].r = t.data[k1].r;
            t.data[k1 + 1].c = t.data[k1].c;
            t.data[k1 + 1].d = t.data[k1].d;
        }
        t.data[k].r = i;
        t.data[k].c = j;
        t.data[k].d = x;
        t.nums ++;
    }
    return true;
}

//将指定位置的元素值赋给变量
bool Assign(TSMatrix t, int &x, int i, int j) {
    int k = 0;
    if (i >= t.rows || j >= t.cols) {
        return false;
    }
    while (k < t.nums && i > t.data[k].r) k ++;
    while (k < t.nums && i == t.data[k].r && j > t.data[k].c) k ++;
    if (t.data[k].r == i && t.data[k].c == j) {
        x = t.data[k].d;
    } else {
        x = 0;
    }
    return true;
}

//输出三元组
void DispTup(TSMatrix t) {
    int k;
    if (t.nums <= 0) {
        return ;
    }
    printf("row=%d\tcol=%d\tnonzero=%d\n", t.rows, t.cols, t.nums);
    printf("----------------------------------\n");
    printf("nonzero element: \n");
    for (int k = 0; k < t.nums; k ++) {
        printf("%d\t%d\t%d\n", t.data[k].r, t.data[k].c, t.data[k].d);
    }
    cout << endl;
}

//稀疏矩阵的转置
void TranTat(TSMatrix t, TSMatrix &tb) {
    int k1 = 0;     //k1记录tb中的元素个数
    tb.rows = t.cols; tb.cols = t.rows; tb.nums = t.nums;
    if (t.nums != 0) {
        for (int v = 0; v < t.cols; v ++) {
            for (int k = 0; k < t.nums; k ++) {
                if (t.data[k].c == v) {
                    tb.data[k1].r = t.data[k].c;
                    tb.data[k1].c = t.data[k].r;
                    tb.data[k1].d = t.data[k].d;
                    k1 ++;
                }
            }
        }
    }
}

//通过三元组输出稀疏矩阵
void DispMatByTup(TSMatrix t) {
    if (t.nums == 0) {
        return ;
    }
    printf("row=%d\tcol=%d\tnonzero=%d\n", t.rows, t.cols, t.nums);
    printf("----------------------------------\n");
    int x = 0, k = 0;
    for (int i = 0; i < M; i ++) {
        for (int j = 0; j < N; j ++) {
            if (t.data[k].r == i && t.data[k].c == j) {
                printf("%d ", t.data[k].d);
                k ++;
            } else {
                printf("0 ");
            }
        }
        cout << endl;
    }
    cout << endl;
}

#endif //TRIPLET









////////////////测试数据/////////////////////
/*
    int a[5][5] = {
        {1, 2, 0, 4, 5},
        {1, 3, 5, 0, 9},
        {2, 0, 0, 0, 0},
        {0 ,0, 0, 0, 0},
        {0, 9, 7, 0, 3},
    };
    TSMatrix m;
    CreateMat(m, a);
    DispTup(m);
    cout << endl;
    DispMatByTup(m);
    cout << endl;

    for (int i = 1; i < 3; i ++) {
        for (int j = 2; j < 4; j ++) {
            Value(m, 6, i, j);
        }
    }
    
    DispTup(m);
    cout << endl;
    DispMatByTup(m);
    cout << endl;
    TSMatrix mt;
    TranTat(m, mt);
    DispMatByTup(m);
    cout << endl;
    DispMatByTup(mt);
    return 0;
*/