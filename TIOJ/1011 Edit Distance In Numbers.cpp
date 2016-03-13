#include <bits/stdc++.h>
using namespace std;
int main() {
    unsigned int a, b;
    cin >> a >> b;
    int ca = 31, cb = 31;
    while (ca >= 0 && !(a >> ca)) ca--;
    while (cb >= 0 && !(b >> cb)) cb--;
    while (ca >= 0 && cb >= 0 && (a >> ca) == (b >> cb)) ca--, cb--;
    cout << ca + cb + 2 << endl;
}
