#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct Point {
	int x, y, id;
	bool operator<(const Point &p) const {
		if (x == p.x)
			return y < p.y;
		return x < p.x;
	}
};

bool sby(const Point &a, const Point &b) {
	if (a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}

int main() {
	int n;
	static Point p[1100000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &(p[i].x), &(p[i].y));
		p[i].id = i + 1;
	}
	sort(p, p + n);
	int sqn = sqrt(n);
	int k = 0;
	for (int i = 0, j = 0; i < n; i++) {
		if (p[i].x > j + sqn) {
			j += sqn;
			sort(p + k, p + i, sby);
			k = i;
		}
	}
	sort(p + k, p + n, sby);
	for (int i = 0; i < n; i++) {
		if (i)
			printf(" ");
		printf("%d", p[i].id);
	}
	printf("\n");
}
