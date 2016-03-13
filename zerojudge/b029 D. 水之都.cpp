#include <cstdio> //NAC
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
	static int road[1010][1010];
	int n,m,dst[1010];
	bool hs[1010];
	while(scanf("%d%d",&n,&m),n||m) {
		int i,j;
		for(i=0; i<=n; i++)
			for(j=0; j<=n; j++)
				road[i][j]=-1;
		for(i=0; i<=n; i++)
			dst[i]=-1;
		for(i=0; i<=n; i++)
			hs[i]=false;
		int fr,to,w;
		for(i=0; i<m; i++) {
			scanf("%d%d%d",&fr,&to,&w);
			if(w>road[fr][to])
				road[fr][to]=road[to][fr]=w;
		}
		scanf("%d%d",&fr,&to);
		dst[fr]=0;
		hs[fr]=true;
		for(i=1; i<=n; i++)
			if(road[fr][i]>=0)
				dst[i]=road[fr][i];
		int nxt,nxtn;
		for(j=1; j<=n; j++) {
			nxtn=-1;
			for(i=1; i<=n; i++)
				if(!hs[i] && dst[i]>nxtn)
					nxtn=dst[i],nxt=i;
			if(nxtn==-1) {
				puts("0");
				break;
			}
			if(nxt==to) {
				printf("%d\n",dst[to]);
				break;
			}
			hs[nxt]=true;
			for(i=1; i<=n; i++)
				if(road[nxt][i]>=0)
					dst[i]=max(min(dst[nxt],road[nxt][i]),dst[i]);
		}
	}
}
