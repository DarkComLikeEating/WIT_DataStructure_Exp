/*----------������run.cpp��ʵ��----------*/
#include <iostream>
#include "PostExpCompute.cpp"
#include "PostExpTransform.cpp"

using namespace std;

int main() {
    char exp[] = "(56-20)/(4+2)";
    char postexp[Maxsize];
    trans(exp, postexp);
    cout << "��׺���ʽ��" << exp << endl;
    cout << "��׺���ʽ��" << postexp << endl;
    cout << "���ʽ��ֵ��" << ComputeValue(postexp) << endl;
    return 0;
}
