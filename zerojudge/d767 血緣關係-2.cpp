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

int ft[16][30100],lv[30100];

void getlv(int x) {
	if(ft[0][x]==x) {
		lv[x]=1;
		return;
	}
	if(lv[ft[0][x]]==-1)
		getlv(ft[0][x]);
	lv[x]=lv[ft[0][x]]+1;
}

void mkft(int n) {
	int p=0,i,l=1;
	do {
		p++;
		l*=2;
		for(i=1; i<=n; i++)
			ft[p][i]=ft[p-1][ft[p-1][i]];
	} while(p<15);
}

int eqlv(int &x,int &y) {
	int p=15,l=pow(2,15),r=0;
	if(lv[x]<lv[y])
		swap(x,y);
	while(lv[x]>lv[y]) {
		if(l<=lv[x]-lv[y])
			r+=l,x=ft[p][x];
		l/=2,p--;
	}
	return r;
}

int lca(int &x,int &y) {
	int p=15,l=pow(2,15),r=0;
	if(x==y)
		return 0;
	while(l) {
		if(ft[p][x]==ft[p][y])
			p--,l/=2;
		else {
			r+=l;
			x=ft[p][x];
			y=ft[p][y];
		}
	}
	return r+1;
}

int main () {
	int n,q;
	int i;
	while(~scanf("%d%d",&n,&q)) {
		for(i=0; i<=n; i++)
			ft[0][i]=i;
		for(i=1; i<=n; i++) {
			int x;
			while(scanf("%d",&x),x)
				ft[0][x]=i;
		}
		memset(lv,-1,sizeof(lv));
		for(i=1; i<=n; i++)
			if(lv[i]==-1)
				getlv(i);
		mkft(n);
		for(i=0; i<q; i++) {
			int ans=0;
			int x,y;
			scanf("%d%d",&x,&y);
			ans+=eqlv(x,y);
			ans+=2*lca(x,y);
			if(x==y)
				printf("%d ",x);
			else
				printf("%d ",ft[0][x]);
			printf("%d\n",ans);
		}
	}
}
