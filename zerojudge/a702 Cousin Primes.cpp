#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<int> find_primes(int MX) {
	set<int> primes;
	bool *notprime = new bool[MX + 1]();
	for (int i = 2; i <= MX; i++) {
		if (!notprime[i]) {
			primes.insert(i);
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

 vector<pair<int, int> > find_cousin_primes(int MX) {
	 set<int> primes = find_primes(MX);
	 vector<pair<int, int> > cousin_primes;
	 for (int i : primes) {
		 if (primes.find(i + 4) != primes.end()) {
			 cousin_primes.push_back({ i, i + 4 });
		 }
	 }
	 return cousin_primes;
}

int main() {
	ios::sync_with_stdio(false);
	int s;
	vector<pair<int, int> > cousin_primes = find_cousin_primes(20000000);
	while (cin >> s) {
		cout << "(" << cousin_primes[s - 1].first << ", " << cousin_primes[s - 1].second << ")" << endl;
	}
}