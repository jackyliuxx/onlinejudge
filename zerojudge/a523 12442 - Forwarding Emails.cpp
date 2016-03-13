#include<iostream>
#include<stdio.h>
using namespace std;
int a[50010][2];
int acx(int n,int w){
	int y;
	if(a[n][0]==0)
		return a[n][1]+w;
	w++;
	y=a[n][0];
	a[n][0]=0;
	w=acx(y,w);
	a[n][1]=w;
	return w;
}
int main(){
	int t,n,i,x,y,ans,ans2,k=1;
	scanf("%d",&t);
	while(t--){
		for(i=0;i<50001;i++)
			a[i][1]=0,a[i][0]=0;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d%d",&x,&y);
			a[x][0]=y;
		}
		ans=0;
		for(i=1;i<=n;i++)
			if(a[i][0])
				acx(i,0);
		for(i=1;i<=n;i++)
			if(a[i][1]>ans)
				ans=a[i][1],ans2=i;
		printf("Case %d: %d\n",k++,ans2);
	}
}