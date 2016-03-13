#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
#define maxn 510
vector<int> rright[maxn],upper[maxn];
int n,w,longr[maxn],longu[maxn],maxr,maxu;
void input(){
	int a,b,c;
	cin>>a>>b>>c;
	if(c)
		upper[b].push_back(a);
	else
		rright[b].push_back(a);
}

void dfsr(int now,int mr){
	int i;
	if(longr[now]>=mr)
		return;
	longr[now]=mr;
	if(maxr<mr)
		maxr=mr;
	for(i=0;i<rright[now].size();i++)
		dfsr(rright[now][i],mr+1);
}

void dfsu(int now,int mu){
	int i;
	if(longu[now]>=mu)
		return;
	longu[now]=mu;
	if(maxu<mu)
		maxu=mu;
	for(i=0;i<upper[now].size();i++)
		dfsu(upper[now][i],mu+1);
}


int main(){
	int t,i;
	while(cin>>n>>w){
		for(i=0;i<=n;i++)
			rright[i].clear(),upper[i].clear();
		t=n*(n-1)/2;
		maxr=maxu=0;
		for(i=0;i<=n;i++)
			longr[i]=longu[i]=0;

		for(i=0;i<t;i++)
			input();

		for(i=1;i<=n;i++)
			dfsr(i,1);
		for(i=0;i<=n;i++)
			dfsu(i,1);
		cout<<maxr*maxu*w*w<<endl;
	}
}