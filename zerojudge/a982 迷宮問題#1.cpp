#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<char>> mp(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mp[i][j];
        }
    }
    int ans = -1;
    queue<int> qx, qy, qstep;
    if (mp[1][1] != '#') {
        qx.push(1), qy.push(1), qstep.push(1);
    }
    while (qx.size()) {
        int x = qx.front(), y = qy.front(), step = qstep.front();
        qx.pop(), qy.pop(), qstep.pop();
        if (x == n - 2 && y == n - 2) {
            ans = step;
            break;
        }
        int wx[4] = {1, 0, -1, 0}, wy[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nx = x + wx[i], ny = y + wy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || mp[nx][ny] == '#') {
                continue;
            }
            qx.push(nx);
            qy.push(ny);
            qstep.push(step + 1);
            mp[nx][ny] = '#';
        }
    }
    if (ans == -1) {
        cout << "No solution!" << endl;
    } else {
        cout << ans << endl;
    }
}
