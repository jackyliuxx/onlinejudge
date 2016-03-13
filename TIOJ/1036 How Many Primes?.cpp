#include <bits/stdc++.h>
using namespace std;

vector<int> primes;

void getprimes(int n) {
    vector<bool> isp(n, true);
    for (int i = 2; i < n; i++) {
        if (isp[i]) {
            primes.push_back(i);
        }
        for (auto p : primes) {
            if (i * p >= n) break;
            isp[i * p] = false;
            if (i % p == 0) break;
        }
    }
}


int main() {
    getprimes(10001000);
    int m;
    cin >> m;
    while (m--) {
        int n;
        cin >> n;
        cout << lower_bound(primes.begin(), primes.end(), n + 1) - primes.begin() << endl;
    }
}
