#include <iostream>
#include <algorithm>
using namespace std;

class Point {
public:
	Point() : x(0), y(0) {}
	bool operator<(const Point &p) const {
		return x == p.x ? y < p.y : x < p.x;
	}
	friend istream &operator>>(istream &in, Point &p) {
		in >> p.x >> p.y;
		return in;
	}
	friend ostream &operator<<(ostream &out, const Point &p) {
		cout << p.x << ' ' << p.y;
		return out;
	}
private:
	int x, y;
};

int main() {
	int n;
	cin >> n;
	Point a[1024];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
}