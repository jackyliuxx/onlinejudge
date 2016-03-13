#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
#define maxn 100010
vector<int> road[maxn],stack;
int n,m,ffind[maxn],order[maxn],o,ring[maxn],havering[maxn],ans[maxn],an=0;

void input(){
	int a,b;
	cin>>a>>b;
	road[a].push_back(b);
}

void dfs(int now){
	int i,here=0,take;
	if(ffind[now])
		return;
	stack.push_back(now);
	ffind[now]=1;
	ring[now]=order[now]=o++;
	for(i=0;i<road[now].size();i++)
		dfs(road[now][i]);
	for(i=0;i<road[now].size();i++)
		if(ring[road[now][i]]<ring[now])
			if(havering[road[now][i]]==0)
				ring[now]=ring[road[now][i]];
	if(ring[now]==order[now]){
		do{
			take=stack.back();
			havering[take]=1;
			stack.pop_back();
			here++;
		}while(take!=now);
		ans[an++]=here;
	}
}

int main(){
	int i,j;
	while(cin>>n>>m){
		an=0;
		for(i=0;i<=n;i++)
			road[i].clear();
		for(i=0;i<m;i++){
			input();
		}
		o=1;
		memset(ffind,0,sizeof(ffind));
		memset(ring,0,sizeof(ring));
		memset(havering,0,sizeof(havering));
		stack.clear();
		for(i=1;i<=n;i++)
			if(ffind[i]==0)
				dfs(i);
		sort(ans,ans+an);
		for(i=0;i<an-1;i++)
			cout<<ans[i]<<' ';
		cout<<ans[an-1]<<endl;

	}
}