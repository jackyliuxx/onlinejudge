#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool test(vector<int> &v, int x) {
    for (int i = 1, j = 0; i < v.size(); i++) {
        while (v[i] - v[j] > x)
            j++;
        if (v[i] - v[j] == x)
            return true;
    }
    return false;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    while (q--) {
        int x;
        cin >> x;
        if (test(v, x)){
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}
