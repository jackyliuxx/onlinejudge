#include <iostream>
#include <algorithm>
using namespace std;
int n,t,a[100000],x[100000],i,y,c,b[200000],j;
int main () {
	cin >> n;
	while (n--) {
		cin >> t;
		c=0;
		y=0;
		for (i=0;i<t;i++) {
			cin >> a[i];
			cin >> x[i];
			x[i]=x[i]/a[i];
			for (j=0;j<a[i];j++)
				b[c+j]=x[i];
			c=c+abs(a[i]);
		}
		c=c/2+c%2-1;
		c=b[c];
		for (i=0;i<t;i++)
			y=y+abs(a[i]*(c-x[i]));
		cout << y << endl;
	}
}

