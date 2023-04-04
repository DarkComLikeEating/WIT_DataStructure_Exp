/*----------以下是PostExpCompute.cpp的实现----------*/
#include "NumStack.cpp"
#include <iostream>

using namespace std;

double ComputeValue(char * postexp) {
    double d, a, b, c, e;
    SqStack1 * op;
    InitStack1(op);
    while (* postexp != '\0') {
        switch (* postexp) {
            case '+':
                Pop1(op, a);
                Pop1(op, b);
                c = b + a;
                Push1(op, c);
                break;
            case '-':
                Pop1(op, a);
                Pop1(op, b);
                c = b - a;
                Push1(op, c);
                break;
            case '*':
                Pop1(op, a);
                Pop1(op, b);
                c = b * a;
                Push1(op, c);
                break;
            case '/':
                Pop1(op, a);
                Pop1(op, b);
                if (a != 0) {
                    c = b / a;
                    Push1(op, c);
                    break;
                } else {
                    cout << endl << "除零错误！" << endl;
                    exit(0);
                }
                break;
            default:
                d = 0;
                while (* postexp >= '0' && * postexp <= '9') {
                    d = 10 * d + * postexp - '0';
                    postexp ++;
                }
                Push1(op, d);
                break;
        }
        postexp ++;
    }
    GetTop1(op, e);
    DestroyStack1(op);
    return e;
}
