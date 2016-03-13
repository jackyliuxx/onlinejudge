#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return a ? gcd(b%a, a) : b;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int gol;
    cin >> gol;
    int vgcd = v[0];
    for (int i = 1; i < n; i++) {
        vgcd = gcd(vgcd, v[i]);
    }
    if (gol % vgcd) {
        cout << -1 << endl;
    } else if (gol > *max_element(v.begin(), v.end())) {
        cout << -1 << endl;
    } else {
        set<vector<int>> hs;
        queue<vector<int>> pq;
        queue<int> stq;
        pq.push(vector<int>(n, 0));
        stq.push(0);
        while (pq.size()) {
            vector<int> p = pq.front();
            int st = stq.front();
            pq.pop();
            stq.pop();
            for (int i = 0; i < n; i++) {
                if (p[i] == gol) {
                    cout << st << endl;
                    return 0;
                }
            }
            for (int i = 0; i < n; i++) {
                vector<int> np = p;
                np[i] = 0;
                if (hs.find(np) == hs.end()) {
                    hs.insert(np);
                    pq.push(np);
                    stq.push(st + 1);
                }
                np[i] = v[i];
                if (hs.find(np) == hs.end()) {
                    hs.insert(np);
                    pq.push(np);
                    stq.push(st + 1);
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j) continue;
                    vector<int> np = p;
                    np[i] = max(0, p[i] + p[j] - v[j]);
                    np[j] = min(p[i] + p[j], v[j]);
                    if (hs.find(np) == hs.end()) {
                        hs.insert(np);
                        pq.push(np);
                        stq.push(st + 1);
                    }
                }
            }
        }
    }
}
