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
	int t,n,i;
	static int a[1001000];
	static bool s[1001000],b[1001000];
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for(i=0; i<n; i++)
			s[i]=b[i]=false;
		for(i=0; i<n; i++)
			scanf("%d",a+i);
		int mm=a[0];
		for(i=1; i<n; i++)
			if(mm<a[i])
				s[i]=true,mm=a[i];
		mm=a[n-1];
		for(i=n-2; i>=0; i--)
			if(mm>a[i])
				b[i]=true,mm=a[i];
		int ans=0;
		for(i=0; i<n; i++)
			if(s[i]&&b[i])
				ans++;
		printf("%d\n",ans);
	}
}
