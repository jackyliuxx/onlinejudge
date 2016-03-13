#include <iostream>
#include <algorithm>
using namespace std;
int abs (int a) {
	if (a > 0 )
		return a;
	else 
		return -a;
} 

bool cmp (int a, int b) {
	return abs > abs(b);
}
int main () {
	int  p, t, p1, ans;
	int f[100000];
	while (cin >> p)
		while (p--) {
			cin >> p1;
			for (t=0;t<p1;t++)
				cin >> f[t];
			sort (f,f+p1,cmp);
			ans = 1;
			for (t=0;t<p1;t++) {
				if((f[t]>0&&f[t+1]<0) || (f[t]<0 && f[t+1]>0))
					ans++;
			}
			cout << ans << endl;
		}
}