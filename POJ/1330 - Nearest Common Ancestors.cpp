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
#define MAXN 10010
using namespace std;

int lca[MAXN][MAXN];
vector<int> kids[MAXN];
int hs[MAXN];
int father[MAXN];
bool rrrr[MAXN];

int ffa(int x) {
	return father[x]==x ? x : father[x]=ffa(father[x]);
}

void flca(int n) {
	if(hs[n]) return;
	hs[n]=true;
	int i;
	for(i=1; i<=n; i++)
		if(hs[i])
			lca[n][i]=lca[i][n]=ffa(i);
	for(i=0; i<kids[n].size(); i++) {
		flca(kids[n][i]);
		father[kids[n][i]]=n;
	}
}

int main () {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);
		int i;
		for(i=0; i<=n; i++)
			kids[i].clear();
		for(i=0; i<=n; i++)
			hs[i]=false;
		for(i=0; i<=n; i++)
			father[i]=i;
		for(i=0; i<=n; i++)
			rrrr[i]=false;
		int x,y;
		for(i=0; i<n-1; i++) {
			scanf("%d%d",&x,&y);
			kids[x].push_back(y);
			rrrr[y]=true;
		}
		int rt;
		for(i=1; i<=n; i++)
			if(!rrrr[i])
				rt=i;
		scanf("%d%d",&x,&y);
		flca(rt);
		printf("%d\n",lca[x][y]);
	}
}
