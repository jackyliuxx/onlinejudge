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

int n,m,sp=0;
vector<int> e[51400];
bool hs[51400]={};
int sn[51400];

int fb(int x,int f,int &ans){
	hs[x]=true;
	sn[x]=sp++;
	int i,msn=sn[x],nsn,isp=0;
	for(i=0;i<e[x].size();i++){
		if(!hs[e[x][i]]){
			nsn=fb(e[x][i],x,ans);
			if(nsn>=sn[x]){
				if(f)
					isp=1;
				else
					f++;
			}
			msn=min(msn,nsn);
		}
		else if(e[x][i]!=f){
			msn=min(msn,sn[e[x][i]]);
		}
	}
	ans+=isp;
	return sn[x]=msn;
}


int main () {
	scanf("%d%d",&n,&m);
	int i,x,y;
	for(i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	int ans=0;
	for(i=1;i<=n;i++)
		fb(i,0,ans);
	printf("%d\n",ans);
}
