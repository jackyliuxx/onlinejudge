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

bool rvs(int a,int b){
	return a>b;
}

int main () {
	int t;
	int n,a[101000];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int i;
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		sort(a,a+n,rvs);
		int tt=0;
		for(i=1;i<=n && a[i-1]>i;i++)
			tt+=a[i-1]-i;
		printf("%d\n",tt);
	}
}
