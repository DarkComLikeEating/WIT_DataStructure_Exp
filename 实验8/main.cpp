////////////////main.cpp///////////////////
#include "graph.cpp"
#include "TopSort.h"
#include <iostream>

using namespace std;

int main() {
    AdjGraph * G;
    int A[6][6] = {
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 1},
        {0, 0, 0, 1, 0, 0}
    };
    int n = 6, e = 6;
    CreateAdj(G, A, n, e);
    cout << "ͼG��һ����������Ϊ:";
    TopSort(G);
    DestroyAdj(G);
    return 0;
}