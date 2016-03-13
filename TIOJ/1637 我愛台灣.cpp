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
using namespace std;

int main () {
	long long ans;
	int n;
	ans=0;
	int i;
	static long long stk[1001000],stkn[1001000],sp;
	scanf("%d",&n);
	int x;
	stk[0]=2147483648,stkn[0]=0,sp=1;
	for(i=1;i<=n;i++){
		if(i==n)
			x=2147483647;
		else
			scanf("%d",&x);
		while(stk[sp-1]<=x){
			ans+=stk[sp-1]*(stkn[sp-1]-stkn[sp-2])*(i-stkn[sp-1]);
			sp--;
		}
		stk[sp]=x;
		stkn[sp]=i;
		sp++;
	}
	printf("%I64d\n",ans);
}
