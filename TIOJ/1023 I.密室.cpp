#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    ios::sync_with_stdio(false);
    while (cin >> n) {
        vector<int> r(n), s(n);
        for (int i = 0; i < n; i++) {
            cin >> r[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        sort(r.begin(), r.end());
        sort(s.begin(), s.end());
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += r[i] * s[i];
        }
        cout << ans << endl;
    }
}
