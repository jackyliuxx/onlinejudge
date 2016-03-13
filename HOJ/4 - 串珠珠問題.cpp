#include <bits/stdc++.h>
using namespace std;

long long ct(vector<int> &v, int bg, int ed) {
    if (ed - bg < 2)
        return 0;
    int md = (bg + ed) / 2;
    long long r = ct(v, bg, md) + ct(v, md, ed);
    queue<int> q1, q2;
    for (int i = bg; i < md; i++) {
        q1.push(v[i]);
    }
    for (int i = md; i < ed; i++) {
        q2.push(v[i]);
    }
    for (int i = bg; i < ed; i++) {
        if (q1.empty()) {
            v[i] = q2.front();
            q2.pop();
        }
        else if (q2.empty()) {
            v[i] = q1.front();
            q1.pop();
        }
        else {
            if (q1.front() > q2.front()) {
                r += q1.size();
                v[i] = q2.front();
                q2.pop();
            }
            else {
                v[i] = q1.front();
                q1.pop();
            }
        }
    }
    return r;
}

int main() {
    int n;
    while (~scanf("%d", &n) && n) {
        vector<int> v(n), pos(n + 1);
        for (int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
            pos[v[i]] = i;
        }
        vector<int> v2 = v;
        long long ar = ct(v2, 0, n);
        long long ans = ar;
        for (int i = 1; i <= n; i++) {
            ar -= pos[i];
            ar += n - pos[i] - 1;
            ans = min(ans, ar);
        }
        printf("%lld\n", ans);
    }
}
