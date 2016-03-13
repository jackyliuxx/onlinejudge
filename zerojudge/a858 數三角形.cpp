#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int ans = n * (n - 1) * (n - 2) / 6;
	int nt = 0;
	for (int i = 0; i < n; i++) {
		int c1 = 0, c2 = 0;
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			if (x == 1) {
				c1++;
			}
			if (x == 2) {
				c2++;
			}
		}
		nt += c1 * c2;
	}
	ans -= nt / 2;
	cout << ans << endl;
}