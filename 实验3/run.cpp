/*----------以下是run.cpp的实现----------*/
#include <iostream>
#include "PostExpCompute.cpp"
#include "PostExpTransform.cpp"

using namespace std;

int main() {
    char exp[] = "(56-20)/(4+2)";
    char postexp[Maxsize];
    trans(exp, postexp);
    cout << "中缀表达式：" << exp << endl;
    cout << "后缀表达式：" << postexp << endl;
    cout << "表达式的值：" << ComputeValue(postexp) << endl;
    return 0;
}
