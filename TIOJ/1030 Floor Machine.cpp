#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    ios::sync_with_stdio(false);
    while (cin >> n, n) {
        long long tt = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            tt += x;
            mx = max(mx, x);
        }
        cout << tt + mx + 1 << endl;
    }
}
