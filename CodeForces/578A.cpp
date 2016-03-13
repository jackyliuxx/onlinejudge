#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    if (a == b) {
        cout << b << endl;
        return 0;
    }
    int l = 1, r = a + b, y = b;
    double ans = 0;
    while (r - l > 1) {
        int k = (r + l) / 2;
        ans = (0.0 + b + a) / (2 * k);
        if (ans >= y) {
            l = k;
            continue;
        }
        ans = (0.0 + b - a) / (2 * k);
        if (ans >= y) {
            l = k;
            continue;
        }
        r = k;
    }
    ans = (0.0 + b - a) / (2 * l);
    if (ans >= y) {
        cout << ans << endl;
        return 0;
    }
    ans = (0.0 + b + a) / (2 * l);
    if (ans >= y) {
        cout << ans << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}
