#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int main(){
	int n,i,j,ans[30],c[30],k,a[30][30];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&k);
		ans[k]=i;
	}
	while(~scanf("%d",&k)){
		c[k]=0;
		for(i=1;i<n;i++){
			scanf("%d",&k);
			c[k]=i;
		}
		for(i=0;i<=n;i++)
			a[i][0]=a[0][i]=0;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				a[i][j]= (ans[i]==c[j]) ? (a[i-1][j-1]+1) : (max(a[i][j-1],a[i-1][j]));
		printf("%d\n",a[i-1][j-1]);
	}
}