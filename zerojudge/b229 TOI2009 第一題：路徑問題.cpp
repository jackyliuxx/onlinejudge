// by jackyliuxx
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <list>
#include <map>
using namespace std;

unsigned long long a[60][2];

int main () {
	int n;
	int i;
	a[1][0]=a[1][1]=1;
	for(i=2;i<=50;i++){
		a[i][0]=a[i-1][0]+2*a[i-1][1];
		a[i][1]=a[i-1][0]+a[i-1][1];
	}
	while(cin>>n)
		cout<<a[n][0]+a[n][1]*2<<endl;
}
