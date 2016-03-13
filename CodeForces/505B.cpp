#include<bits/stdc++.h>
using namespace std;

bool rd[110][110][110]={};
bool hs[110];

bool cnct(int k,int x,int y,int n){
	if(hs[x])
		return false;
	hs[x]=true;
	if(x==y)
		return true;
	for(int i=1;i<=n;i++){
		if(rd[k][x][i])
			if(cnct(k,i,y,n))
				return true;
	}
	return false;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		rd[z][x][y]=rd[z][y][x]=1;
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		int ans=0;
		for(int i=1;i<=m;i++){
			memset(hs,0,sizeof(hs));
			if(cnct(i,x,y,n))
				ans++;
		}
		printf("%d\n",ans);
	}
}
