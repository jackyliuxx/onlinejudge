#include <iostream>
using namespace std;
const long long M = 1000000009;
int main() {
	long long n;
	while (cin >> n) {
		long long r = n, ans = 0;
		for (long long i = 2; i <= r; i++) {
			ans += n % i;
			long long k = n / i;
			if (k < i)
				k = i;
			long long k2 = (n - (i - 1) * (k + 1) + n - (i - 1) * r);
			if (k2 >= M) k2 %= M;
			long long k3 = r - k;
			if (k3 >= M) k3 %= M;
			k2 *= k3;
			if (k2 >= M) k2 %= M;
			k2 *= 500000005;
			if (k2 >= M) k2 %= M;
			ans += k2;
			if (ans >= M) ans %= M;
			r = k;
		}
		cout << ans << endl;
	}
}