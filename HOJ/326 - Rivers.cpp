//by jackyliuxx
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

int dp[150][60];

struct city {
	int nxt,rl,wd,f,sl;
};

city rvs[150];

int f(int x) {
	return rvs[x].f==x ? x : rvs[x].f=f(rvs[x].f);
}

int godo(int n,int k) {
	int ans=0;
	int i;
	for(; k<n; k++) {
		int nx,mn=2147483647;
		for(i=1; i<=n; i++) {
			int nl=rvs[i].wd*(rvs[i].rl+rvs[rvs[i].nxt].sl);
			if(rvs[i].wd!=-1 && mn>nl) {
				mn=nl;
				nx=i;
			}
		}
		ans+=mn;
		rvs[f(rvs[nx].nxt)].wd+=rvs[nx].wd;
		rvs[nx].f=rvs[nx].nxt;
		rvs[nx].sl+=rvs[rvs[nx].nxt].sl+rvs[nx].rl;
		rvs[nx].wd=-1;
	}
	return ans;
}



int main () {
	int n,k;
	scanf("%d%d",&n,&k);
	int i;
	rvs[0].nxt=rvs[0].rl=rvs[0].wd=rvs[0].f=0;
	for(i=1; i<=n; i++) {
		scanf("%d%d%d",&rvs[i].wd,&rvs[i].nxt,&rvs[i].rl);
		rvs[i].f=i;
		rvs[i].sl=0;
	}
	printf("%d\n",godo(n,k));
}
