#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

void getans(vector<int> &v, int x, vector<int> &now, int sum, int m, vector< vector<int> > &ans) {
    if (sum == m) {
        ans.push_back(now);
        return;
    }
    if (sum > m) {
        return;
    }
    if (x == (int) v.size()) {
        return;
    }
    now.push_back(v[x]);
    getans(v, x + 1, now, sum + v[x], m, ans);
    now.pop_back();
    getans(v, x + 1, now, sum, m, ans);
}   

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector< vector<int> > ans;
    vector<int> now;
    getans(v, 0, now, 0, m, ans);
    if (ans.empty()) {
        cout << -1 << endl;
    } else {
        for (auto i : ans) {
            bool sp = false;
            for (auto j : i) {
                if (sp) {
                    cout << " ";
                }
                cout << j;
                sp = true;
            }
            cout << endl;
        }
    }
}
