#include <iostream>
using namespace std;

int gcd(int a, int b) {
	return a ? gcd(b % a, a) : b;
}

int main() {
	int a, b;
	while (cin >> a >> b) {
		cout << gcd(a, b) << endl;
	}
}