#include <bits/stdc++.h>
using namespace std;

int DP[1010][1010], v[1010];

int take(int l, int r) {
    if (DP[l][r] != -1) {
        return DP[l][r];
    }
    if (l == r) {
        return 0;
    }
    return DP[l][r] = max(v[l] - take(l + 1, r), v[r - 1] - take(l, r - 1));
}

int main() {
    int n;
    cin >> n;
    int all = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        all += v[i];
    }
    memset(DP, -1, sizeof(DP));
    int aw = take(0, n);
    cout << (all + aw) / 2 << ' ' << (all - aw) / 2 << endl;
}
