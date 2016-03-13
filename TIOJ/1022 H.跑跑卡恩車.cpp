#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mp(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mp[i][j];
            }
        }
        int wx[4] = {0, 1, 0, -1}, wy[4] = {1, 0, -1, 0};
        set<pair<int, int>> hs;
        queue<pair<int, int>> pq;
        queue<int> stq;
        hs.insert({0, 0});
        pq.push({0, 0});
        stq.push(0);
        while (pq.size()) {
            auto p = pq.front();
            auto st = stq.front();
            int x = p.first, y = p.second;
            if (x == n - 1 && y == m - 1) {
                cout << st << endl;
                break;
            }
            pq.pop();
            stq.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + wx[i], ny = y + wy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (abs(mp[x][y] - mp[nx][ny]) <= 5 && hs.find({nx, ny}) == hs.end()) {
                    hs.insert({nx, ny});
                    pq.push({nx, ny});
                    stq.push(st + 1);
                }
            }
        }
    }
}
