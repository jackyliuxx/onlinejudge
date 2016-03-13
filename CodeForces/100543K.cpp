#include<bits/stdc++.h>
using namespace std;

struct item{
	int v,c;
	bool operator<(item x)const{
		return (c!=x.c?c<x.c:v>x.v);
	}
};

//int dpp[160000][12];
int n,k;
item a[160000];
/*
int dp(int x,int y){
	if(~dpp[x][y])
		return dpp[x][y];
	if(x==n || n-x<=y)
		return 0;
	int r=0;
	if(y)
		r=min(dp(x+1,y-1)-a[x].c,a[x].v-a[x].c);
	else
		r=a[x].v-a[x].c;
	return dpp[x][y]=max(r,dp(x+1,y));
}
*/

int dp(int x,int y){
	if(x==n || n-x<=y)
		return 0;
	int mx=0;
	for(int i=x;i<n;i++){
		swap(a[x],a[i]);
		mx=max(mx,(y?min(dp(x+1,y-1)-a[x].c,a[x].v-a[x].c):a[x].v-a[x].c));
		swap(a[x],a[i]);
	}
	return mx;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		//memset(dpp,-1,sizeof(dpp));
		for(int i=0;i<n;i++)
			cin>>a[i].v>>a[i].c;
		//sort(a,a+n);
		cout<<dp(0,k)<<endl;
	}
}
