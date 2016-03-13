#include <bits/stdc++.h>
using namespace std;

int z(const string &s1, const string &s2) {
    string s = s1 + s2;
    vector<size_t> zv(s.size());
    for (size_t i = 1, l = 1, r = 1; i < s.size(); i++) {
        if (i < r) {
            if (zv[i - l] + i < r) {
                zv[i] = zv[i - l];
            } else {
                zv[i] = r - i;
            }
        }
        while (i + zv[i] < s.size() && s[i + zv[i]] == s[zv[i]]) {
            zv[i]++;
        }
        if (i + zv[i] > r) {
            l = i;
            r = i + zv[i];
        }
        if (i >= s1.size() && zv[i] <= s1.size() && i + zv[i] == s.size()) {
            return zv[i];
        }
    }
    return 0;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << z(s1, s2) << endl;
}
