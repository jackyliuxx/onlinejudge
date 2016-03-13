#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string s;
    while (getline(cin, s)) {
        stringstream ss(s);
        long long x, ans = 0;
        while (ss >> x) {
            if (ans == 0 && x == 0) {
                return 0;
            }
            for (int t = 30; t >= 0; t--) {
                if (x & (1 << t)) {
                    ans += (1 << t);
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}
