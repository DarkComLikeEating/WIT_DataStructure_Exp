/*----------以下是PostExpTransform.cpp的实现----------*/
#include "OpStack.cpp"

using namespace std;

void trans(char * exp, char postexp[]) {
    char e;
    SqStack * op;
    InitStack(op);
    int i = 0;
    while (* exp != '\0') {
        switch(* exp) {
            case '(': 
                Push(op, '(');
                exp ++;
                break;
            case ')':
                Pop(op, e);
                while (e != '(') {
                    postexp[i ++] = e;
                    Pop(op, e);
                }
                exp ++;
                break;
            case '+':
            case '-':
                while (!StackEmpty(op)) {
                    GetTop(op, e);
                    if (e != '(') {
                        postexp[i ++] = e;
                        Pop(op, e);
                    } else {
                        break;
                    }
                }
                Push(op, * exp);
                exp ++;
                break;
            case '*':
            case '/':
                while (!StackEmpty(op)) {
                    GetTop(op, e);
                    if (e == '*' || e == '/') {
                        postexp[i ++] = e;
                        Pop(op, e);
                    } else {
                        break;
                    }
                }
                Push(op, * exp);
                exp ++;
                break;
            default:
                while (* exp >= '0' && * exp <= '9') {
                    postexp[i ++] = * exp;
                    exp ++;
                }
                postexp[i ++] = '#';
        }
    }
    while (!StackEmpty(op)) {
        Pop(op, e);
        postexp[i ++] = e;
    }
    postexp[i ++] = '\0';
    DestroyStack(op);
}
