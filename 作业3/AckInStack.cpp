#include <iostream>
#include "SqStack.h"

using namespace std;

int main() {
    SqStack * s1;
    int a[] = {1, 3, 5, 6, 2, 9};
    int j = 0;
    for (int i = 0; i < 6; i ++) Push(s1, a[i]);
    GetTop(s1, j); 
    cout << j << endl;
    for (int i = 0; i < 6; i ++) {
        Pop(s1, j);
        cout << j << " ";
    }
    return 0;
}