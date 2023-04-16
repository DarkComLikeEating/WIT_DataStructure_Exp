#include <iostream>

using namespace std;

int Ack(int m, int n) {
    int ans = 0;
    if (m == 0) {
        ans = n + 1;
        cout << "Ack(" << m << ", " << n << ") = " << ans << endl;
        return ans;
    } else if (m != 0 && n == 0) {
        ans = Ack(m - 1, 1);
        cout << "Ack(" << m << ", " << n << ") = " << ans << endl;
        return ans;
    } else if (m != 0 && n != 0) {
        ans = Ack(m - 1, Ack(m, n - 1));
        cout << "Ack(" << m << ", " << n << ") = " << ans << endl;
        return ans;
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << Ack(m, n);
    return 0;
}