#include <iostream>
#include "SqStack.h"

using namespace std;

int Ack2(int m, int n) {
    int t = 0;
    cout << "enter" << endl;
    SqStack * s1, * s2;
    Push(s1, m);    
    Push(s2, n);
    cout << "enter" << endl;
    while (!StackEmpty(s1)) {
        while (m != 0) {
            if (n == 0) {
                m = m - 1;
                n = 1;
                Push(s1, m);
                Push(s2, n);
            } else {
                n = n - 1;
                Push(s1, m - 1);
                Push(s2, -1);
            }
        }
        n = n + 1;
        GetTop(s2, t);
        while ((!StackEmpty(s1) && (t != -1))) {
            Pop(s1, t);
            Pop(s2, t);
            GetTop(s2, t);
        }
        if (!StackEmpty(s1)) {
            GetTop(s1, m);
            Pop(s2, t);
            Push(s2, n);
        }
    }
    return n;
}
//注：未实现，在函数内调用顺序栈会直接停止程序，无法运行
int main() {
    int m, n;
    cin >> m >> n;
    cout << Ack2(m, n);
    return 0;
}