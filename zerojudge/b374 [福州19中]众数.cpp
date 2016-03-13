#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    vector<int> ansn;
    int ansv = 0;
    for (auto i : mp) {
        if (i.second > ansv) {
            ansn.clear();
            ansv = i.second;
        }
        if (i.second == ansv) {
            ansn.push_back(i.first);
        }
    }
    for (auto i : ansn) {
        cout << i << ' ' << ansv << endl;
    }
}
