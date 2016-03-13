#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> v(n), d(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        d[1] = abs(v[1] - v[0]);
        for (int i = 2; i < n; i++) {
            d[i] = min(d[i - 1] + abs(v[i] - v[i - 1]), d[i - 2] + abs(v[i] - v[i - 2]));
        }
        cout << d[n - 1] << endl;
    }
}
