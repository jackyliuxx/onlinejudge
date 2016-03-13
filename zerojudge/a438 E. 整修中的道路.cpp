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
bool havens[32100];
vector<int> road[64100];
int snum[32100],num;
vector<int> savep;
int thisroad[520000][2];
int scc(int n,int fa) {
	int i,mynum,p,si;
	havens[n]=false;
	mynum=snum[n]=num++;
	savep.push_back(n);
	for(i=0; i<road[n].size(); i+=2) {
		if(road[n][i]==fa){
			si=i;
			continue;
		}
		if(havens[road[n][i]])
			p=scc(road[n][i],n);
		else
			p=snum[road[n][i]];
		if(p<mynum)
			mynum=p;
	}
	if(mynum==snum[n]) {
		do {
			p=savep.back();
			savep.pop_back();
			snum[p]=snum[n];
		} while(p!=n);
		if(fa){
		thisroad[road[n][si+1]][0]=mynum;
		thisroad[road[n][si+1]][1]=num;
		}
	}
	else if(fa)
		thisroad[road[n][si+1]][0]=0;
	return mynum;
}

int main () {
	int t,n,m,a,b,d,c,r,i,fr,to,br;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&c,&r);
		for(i=0; i<=c; i++)
			road[i].clear();
		for(i=1; i<=r; i++) {
			scanf("%d%d",&a,&b);
			road[a].push_back(b);
			road[a].push_back(i);
			road[b].push_back(a);
			road[b].push_back(i);
		}
		for(i=0; i<=c; i++)
			havens[i]=true;
		num=1;
		for(i=1; i<=c; i++)
			if(havens[i])
				scc(i,0);
		scanf("%d",&d);
		while(d--) {
			scanf("%d%d%d",&br,&fr,&to);
			if(thisroad[br][0]!=0 && (
				(snum[fr]>=thisroad[br][0] && snum[fr]<thisroad[br][1]) ^
				(snum[to]>=thisroad[br][0] && snum[to]<thisroad[br][1])))
				printf("Y");
			else
				printf("N");
		}
		puts("");
	}
}
