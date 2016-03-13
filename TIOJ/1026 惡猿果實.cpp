#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int tt = 0;
    int st = 0;
    for (int i = 1; tt < n; i <<= 1, st++) {
        tt += i;
    }
    cout << st << endl;
    int d = (tt - n) / 2;
    tt = 0;
    for (int i = 1; tt < n; i <<= 1, d >>= 1) {
        if (d & 1) {
            cout << '-';
        } else {
            cout << '+';
        }
        tt += i;
    }
    cout << endl;
}
