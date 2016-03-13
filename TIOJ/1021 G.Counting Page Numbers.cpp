#include <iostream>
using namespace std;
int main() {
    int n, k;
    while (cin >> n >> k) {
        long long ans = 0;
        for (long long i = 1; n / i; i *= 10) {
            int x = n / i % 10;
            if (x > k) {
                if (k != 0 || n / i / 10) {
                    ans += i;
                }
            } else if (x == k) {
                if (n / i) {
                    ans += n % i + 1;
                }
            }
            if (k != 0 || n / i / 10 == 0) {
                ans += (n / i / 10) * i;
            } else {
                ans += (n / i / 10 - 1) * i;
            }
        }
        cout << ans << endl;
    }
}
