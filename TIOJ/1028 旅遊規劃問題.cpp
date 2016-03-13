#include <bits/stdc++.h>
using namespace std;

int DP[13][1 << 14], nxt[13][1 << 14], dst[13][13], n;

int dp(int x, int p) {
    for (int i = 0; i < n; i++) {
        DP[i][0] = 0;
    }
    for (int k = 1; k <= p; k++) {
        if ((p & k) != k) {
            continue;
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (int i = 0; i < n; i++) {
            if (k & (1 << i)) {
                pq.push({DP[i][k ^ (1 << i)], i, i});
            }
        }
        int hs[13] = {};
        while (pq.size()) {
            auto now = pq.top();
            pq.pop();
            int np = now[1], d = now[0], nxtp = now[2];
            if (hs[np]) {
                continue;
            }
            hs[np] = 1;
            DP[np][k] = d;
            nxt[np][k] = nxtp;
            for (int i = 0; i < n; i++) {
                if (dst[np][i] != -1) {
                    pq.push({dst[np][i] + d, i, np});
                }
            }
        }
    }
    return DP[x][p];
}

int main() {
    int m;
    while (cin >> n >> m) {
        memset(dst, -1, sizeof(dst));
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            dst[a][b] = (dst[a][b] == -1 ? c : min(dst[a][b], c));
            dst[b][a] = (dst[b][a] == -1 ? c : min(dst[b][a], c));
        }
        int k;
        cin >> k;
        int p = 0, bg = -1;
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            if (bg == -1) {
                bg = x;
            } else {
                p |= (1 << x);
            }
        }
        memset(DP, -1, sizeof(DP));
        memset(nxt, -1, sizeof(nxt));
        cout << "Minimum travel distance: " << dp(bg, p) << endl;
        cout << "Travel route:";
        while (bg != -1) {
            cout << ' ' << bg;
            bg = nxt[bg][p];
            p &= ~(1 << bg);
        }
        cout << endl;
    }
}
