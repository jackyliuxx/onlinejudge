//by jackyliuxx
#include <bits/stdc++.h>
using namespace std;

int a[3100][3100];

int dp(int n,int nm,int m){
	if(nm<0)
		nm=0;
	if(a[n][nm]!=-1)
		return a[n][nm];
	if(n==0)
		return a[n][nm]=1;
	int r=dp(n-1,nm-1,m);
	if(nm<=0)
		r+=dp(n-1,m,m);
	return a[n][nm]=r%10000;
}


int main () {
	int n,m;
	memset(a,-1,sizeof(a));
	while(~scanf("%d%d",&n,&m))
		printf("%d\n",dp(n,0,m));
}
