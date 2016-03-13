#include <bits/stdc++.h>
using namespace std;

int mysort(vector<int> &v, vector<int> &tmp, int bg, int ed) {
    if (ed - bg < 2) {
        return 0;
    }
    int r = 0;
    int md = (bg + ed) / 2;
    r += mysort(v, tmp, bg, md);
    r += mysort(v, tmp, md, ed);
    for (int i = bg, j = md, k = bg; k < ed; k++) {
        if (i == md) {
            tmp[k] = v[j];
            j++;
        } else if (j == ed) {
            tmp[k] = v[i];
            i++;
        } else if (v[i] <= v[j]) {
            tmp[k] = v[i];
            i++;
        } else {
            tmp[k] = v[j];
            j++;
            r += md - i;
        }
    }
    for (int i = bg; i < ed; i++) {
        v[i] = tmp[i];
    }
    return r;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> tmp(n);
    cout << mysort(v, tmp, 0, v.size());
}
