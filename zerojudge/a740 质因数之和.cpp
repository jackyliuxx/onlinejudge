#include <iostream>
#include <vector>
using namespace std;

vector<int> find_primes(int MX) {
	vector<int> primes;
	bool *notprime = new bool[MX + 1]();
	for (int i = 2; i <= MX; i++) {
		if (!notprime[i]) {
			primes.push_back(i);
		}
		for (int j : primes) {
			if (i * j > MX) {
				break;
			}
			notprime[i * j] = true;
			if (i % j == 0) {
				break;
			}
		}
	}
	delete[] notprime;
	return primes;
}

int main() {
	vector<int> primes = find_primes(20000000);
	int n;
	while (cin >> n) {
		int ans = 0;
		for (int i : primes) {
			while (n % i == 0) {
				ans += i;
				n /= i;
			}
			if (n == 1) {
				break;
			}
			if (i * i > n) {
				ans += n;
				break;
			}
		}
		cout << ans << endl;
	}
}