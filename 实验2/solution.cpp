/*----------������solution.cpp��ʵ��----------*/
#include "OneVariablePoly.cpp"

using namespace std;

void solution() {
	OneVarPoly * P1, * P2, * ans;
	cout << "���·������һ��һԪ����ʽ." << endl;
	CreatePolyR(P1);
	cout << "����ĵ�һ������ʽ��"; DispPoly(P1);
	cout << endl;
	cout << "���·�����ڶ���һԪ����ʽ." << endl;
	CreatePolyR(P2);
	cout << "����ĵڶ�������ʽ��"; DispPoly(P2);
	cout << endl;
	ans = Add(P1, P2);
	cout << "��������ʽ֮��Ϊ��" << endl;
	DispPoly(ans);

    return;
}