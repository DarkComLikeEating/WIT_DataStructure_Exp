#include <iostream>
#include <stack>

using namespace std;

//Ack(m, n)的递归算法
int Ack1(int m, int n) {
    if (m == 0) {
        return n + 1;
    } else if (m != 0 && n == 0) {
        return Ack1(m - 1, 1);
    } else if (m != 0 && n != 0) {
        return Ack1(m - 1, Ack1(m, n - 1));
    }
}

//Ack(m, n)的递归算法及计算过程 
int Ack3(int m, int n) {
	int ans = 0;
    if (m == 0) {
		ans = n + 1;
		printf("Ack(%d, %d) = %d\n", m, n, ans);
        return ans;
    } else if (m != 0 && n == 0) {
		ans = Ack3(m - 1, 1);
		printf("Ack(%d, %d) = %d\n", m, n, ans);
        return ans;
    } else if (m != 0 && n != 0) {
		ans = Ack3(m - 1, Ack3(m, n - 1));
		printf("Ack(%d, %d) = %d\n", m, n, ans);
        return ans;
    }
}

//Ack(m, n)的非递归算法
int Ack2(int m, int n) {
    stack<int> s1;
	stack<int> s2;
	s1.push(m);
	s2.push(n);
	while (!s1.empty())
	{
		while (m != 0)
		{
			if (n == 0)         //m != 0, n = 0的情况
			{
				m = m - 1;
				n = 1;
				s1.push(m);
				s2.push(n);
			}
			else                //m != 0, n != 0的情况
			{
				n = n - 1;
				s1.push(m - 1);
				s2.push(-1);
			}
		}
		n = n + 1;              //m = 0的情况
		while ((!s1.empty()) && (s2.top() != -1))
		{
			s1.pop();
			s2.pop();
		}
		if(!s1.empty())
		{
			m = s1.top();
			s2.pop();
			s2.push(n);
		}
	}
	return n;
}

int main() {
    int m, n;
    m = 2, n = 1;
    Ack3(m, n);
    return 0;
}