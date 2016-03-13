#include <bits/stdc++.h>
using namespace std;

const int MXN = 1024;
vector<int> primes;
void mkp() {
    bool isnp[MXN] = {};
    for (int i = 2; i < MXN; i++) {
        if(!isnp[i])
            primes.push_back(i);
        for (int j : primes) {
            if (i * j >= MXN)
                break;
            isnp[i * j] = true;
            if (i % j == 0)
                break;
        }
    }
}

int main() {
    int n;
    mkp();
    while (cin >> n) {
        vector<int> ans;
        for (int i : primes) {
            int x = i;
            while (x <= n){
                ans.push_back(x);
                x *= i;
            }
        }
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++) {
            if (i)
                cout << ' ';
            cout << ans[i];
        }
        cout << endl;
    }
}
