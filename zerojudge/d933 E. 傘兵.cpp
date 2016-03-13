#include<iostream>
#include<stdio.h>
using namespace std;
int a[100][100],r,c;
void bfs(int y,int x){
	if(x>0 && a[y][x-1]>a[y][x]+1){
		a[y][x-1]=a[y][x]+1;
		bfs(y,x-1);
	}
	if(y>0 && a[y-1][x]>a[y][x]+1){
		a[y-1][x]=a[y][x]+1;
		bfs(y-1,x);
	}
	if(x<c-1 && a[y][x+1]>a[y][x]+1){
		a[y][x+1]=a[y][x]+1;
		bfs(y,x+1);
	}
	if(y<r-1 && a[y+1][x]>a[y][x]+1){
		a[y+1][x]=a[y][x]+1;
		bfs(y+1,x);
	}
}
int main(){
	int t,n,ri,ci,vi,i,j;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&r,&c,&n);
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
				a[i][j]=20000;
		for(i=0;i<n;i++){
			scanf("%d%d%d",&ri,&ci,&vi);
			if(a[ri-1][ci-1]>vi){
			a[ri-1][ci-1]=vi;
			bfs(ri-1,ci-1);
			}
		}
		for(i=0;i<r;i++){
			for(j=0;j<c;j++)
				printf("%d ",a[i][j]);
			printf("\n");
		}
	}
}