#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#define maxn 13
int ans,n,dell[maxn],delc[2*maxn],dels[2*maxn];
char a[maxn][maxn];
void dfs(int deep,int now){
	int i,j;
	a[deep][now]='Q';
	if(deep==n-1){
		ans++;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)
				printf("%c",a[i][j]);
			printf("\n");
		}
		printf("\n");
		a[deep][now]='x';
		return;
	}
	dell[now]=0;
	dels[deep+now]=0;
	delc[deep-now+n]=0;
	for(i=0;i<n;i++)
		if(dell[i] && dels[deep+1+i] && delc[deep+1-i+n])
			dfs(deep+1,i);
	dell[now]=1;
	dels[deep+now]=1;
	delc[deep-now+n]=1;
	a[deep][now]='x';
}

int main(){
	int i,j;
	while(cin>>n,n){
		ans=0;
		for(i=0;i<n;i++)
			dell[i]=1;
		for(i=0;i<2*n;i++)
			delc[i]=dels[i]=1;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				a[i][j]='x';
		for(i=0;i<n;i++)
			dfs(0,i);
		printf("%d\n\n",ans);
	}
}