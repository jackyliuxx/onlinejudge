#include<bits/stdc++.h>
using namespace std;

int wx[4]={0,1,0,-1},wy[4]={1,0,-1,0};
int n,m;

bool dfs(char mp[][60],bool hs[][60],int x,int y,int px,int py){
	if(x<0 || x>=n || y<0 || y>=m || mp[x][y]!=mp[px][py])
		return false;
	if(hs[x][y])
		return true;
	hs[x][y]=true;
	for(int i=0;i<4;i++){
		int nx=x+wx[i],ny=y+wy[i];
		if(nx==px && ny==py)
			continue;
		if(dfs(mp,hs,nx,ny,x,y))
			return true;
	}
	return false;
}

int main(){
	cin>>n>>m;
	char mp[60][60];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>mp[i][j];
	bool hs[60][60]={};
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!hs[i][j] && dfs(mp,hs,i,j,i,j)){
				puts("Yes");
				return 0;
			}
		}
	}
	puts("No");
}
