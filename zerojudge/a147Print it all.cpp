 #include <iostream>
using namespace std;

int main () {
    long long n, i;
    while (cin >> n, n) {
		i = 1;
		while (i < n) {
			if (i == n) break;
		 
		if (i % 7 == 0) //判別 i + 1後是否為7的倍數
			i += 2; //跳過7的倍數
		else
			i++; 
		
		cout << i-1 << ' ';
		}
		cout << endl;
	}
}