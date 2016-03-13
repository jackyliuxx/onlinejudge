#include <bits/stdc++.h>
using namespace std;

int ans;
vector<int> fv;
void fd(int x, int n, const vector<int> &v) {  
    if (x > n) {
        ans++;
        if (v > fv) {
            fv = v;
        }
        return;
    }
    for (size_t i = 1; i < v.size(); i++) {
        if (x % (v[i] + v[i - 1]) == 0) {
            vector<int> tv(v.size() + 1);
            for (size_t j = 0; j < v.size(); j++) {
                if (j == i) {
                    tv[j] = x;
                }
                if (j >= i) {
                    tv[j + 1] = v[j];
                } else {
                    tv[j] = v[j];
                }
            }
            fd(x + 1, n, tv);
        }
    }
}

int main() {
    int n;
    ans = 0;
    fv.clear();
    cin >> n;
    fd(2, n, {0, 1});
    cout << ans << endl;
    for (size_t i = 0; i < fv.size(); i++) {
        if (i) cout << ' ';
        cout << fv[i];
    }
    cout << endl;
}
