 #include <iostream>
using namespace std;

int main () {
    long long n, i;
    while (cin >> n, n) {
		i = 1;
		while (i < n) {
			if (i == n) break;
		 
		if (i % 7 == 0) //�P�O i + 1��O�_��7������
			i += 2; //���L7������
		else
			i++; 
		
		cout << i-1 << ' ';
		}
		cout << endl;
	}
}