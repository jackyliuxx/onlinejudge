#include<iostream>
#include<stdio.h>
#include<vector>
#include<cstdlib>
#include<cstring>
using namespace std;
#define maxn 10010
vector<int> road[maxn];
vector<int> stack;
int ffind[maxn],ring[maxn],numr,order[maxn],ordern=1,havelink[maxn],havescc[maxn];
int n,m;

void input(){
	int a,b;
	cin>>a>>b;
	road[a].push_back(b);
}

int dfs(int now){
	int i,take;
	if(ffind[now])
		return 0;
	ring[now]=order[now]=ordern++;
	ffind[now]=1;
	stack.push_back(now);
	for(i=0;i<road[now].size();i++){
		dfs(road[now][i]);
	}
	for(i=0;i<road[now].size();i++)
		if(havescc[road[now][i]]==0)
			if(ring[road[now][i]]<ring[now])
				ring[now]=ring[road[now][i]];
	if(ring[now]==order[now]){
		do{
			take=stack.back();
			ring[take]=order[now];
			havescc[take]=1;
			stack.pop_back();
		}while(take!=now);
		numr++;
	}
	return 0;
}

int ffindlink(){
	int i,j;
	for(i=1;i<=n;i++)
			for(j=0;j<road[i].size();j++)
				if(ring[road[i][j]]!=ring[i] && havelink[ring[road[i][j]]]==0)
					havelink[ring[road[i][j]]]=1,numr--;
	return 0;
}
int main(){
	int t,i,k=1;
	scanf("%d",&t);
	while(t--){
		ordern=1;
		cin>>n>>m;
		for(i=0;i<=n;i++)
			road[i].clear();
		for(i=0;i<m;i++)
			input();
		memset(ffind,0,sizeof(ffind));
		stack.clear();
		numr=0;
		memset(order,0,sizeof(order));
		memset(havescc,0,sizeof(havescc));
		for(i=1;i<=n;i++)
			if(ffind[i]==0)
				dfs(i);
		memset(havelink,0,sizeof(havelink));
		ffindlink();
		printf("%d\n",numr);
	}
}