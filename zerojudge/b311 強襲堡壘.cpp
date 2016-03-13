#include <iostream>
#include <algorithm>
using namespace std;

class Fortress {
public:
    int a, b;
    bool operator<(const Fortress &f) const {
        if (a == 0 && b == 0 && (f.a || f.b))
            return true;
        return a * f.b < f.a * b;
    }
};

const long long M = 100000007;

int main() {
    int n;
    cin >> n;
    static Fortress f[110000];
    for (int i = 0; i < n; i++) {
        cin >> f[i].a >> f[i].b;
    }
    sort(f, f + n);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += ans * f[i].b + f[i].a;
        ans %= M;
    }
    cout << ans << endl;
}
