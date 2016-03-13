#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

int main () {
	int t,i,j,n,a[50010],money,all;
	cin>>t;
	while(t--) {
		for(i=0; i<50010; i++)
			a[i]=-1;
		a[0]=1;
		all=0;
		cin>>n;
		for(i=0; i<n; i++) {
			cin>>money;
			all+=money;
			for(j=50010-money; j>=0; j--)
				if(a[j]==1)
					a[j+money]=1;
		}
		for(i=all/2; i<=all; i++)
			if(a[i]==1)
				break;
		printf("%d\n",abs(all-i-i));
	}
}
