#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> v[i][j];
            }
        }
        bool sym = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] != v[n - 1 - i][m - 1 - j]) {
                    sym = false;
                }
            }
        }
        if (sym) {
            cout << "go forward" << endl;
        } else {
            cout << "keep defending" << endl;
        }
    }
}

