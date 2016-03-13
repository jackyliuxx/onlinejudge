#include <iostream>
using namespace std;
int main() {
	int n, m;
	while (cin >> n >> m) {
		bool mp[512][512] = {};
		int px, py;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			if (i) {
				if (x != px) {
					for (int j = px; j != x; j += (x > px ? 1 : -1)) {
						mp[j][y] = true;
					}
				}
				if (y != py) {
					for (int j = py; j != y; j += (y > py ? 1 : -1)) {
						mp[x][j] = true;
					}
				}
			}
			px = x;
			py = y;
		}
		mp[px][py] = true;
		for (int i = 0; i < n + 2; i++) {
			cout << '-';
		}
		cout << endl;
		for (int i = 1; i <= n; i++) {
			cout << '|';
			for (int j = 1; j <= n; j++) {
				cout << (mp[i][j] ? '*' : ' ');
			}
			cout << '|' << endl;
		}
		for (int i = 0; i < n + 2; i++) {
			cout << '-';
		}
		cout << endl;
	}
}