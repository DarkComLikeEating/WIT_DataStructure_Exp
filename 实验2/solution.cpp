/*----------以下是solution.cpp的实现----------*/
#include "OneVariablePoly.cpp"

using namespace std;

void solution() {
	OneVarPoly * P1, * P2, * ans;
	cout << "在下方输入第一个一元多项式." << endl;
	CreatePolyR(P1);
	cout << "输入的第一个多项式："; DispPoly(P1);
	cout << endl;
	cout << "在下方输入第二个一元多项式." << endl;
	CreatePolyR(P2);
	cout << "输入的第二个多项式："; DispPoly(P2);
	cout << endl;
	ans = Add(P1, P2);
	cout << "两个多项式之和为：" << endl;
	DispPoly(ans);

    return;
}