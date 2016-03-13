#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int n,m,c,a[30][2],all,i,mx,d,k=1;
	while(scanf("%d%d%d",&n,&m,&c),n||m||c){
		all=0;
		mx=0;
		for(i=0;i<30;i++)
			a[i][1]=0;
		for(i=0;i<n;i++)
			scanf("%d",&a[i][0]);
		for(i=0;i<m;i++){
			scanf("%d",&d);
			if(a[d-1][1]==0)
				a[d-1][1]=1,all+=a[d-1][0];
			else
				a[d-1][1]=0,all-=a[d-1][0];
			mx=max(mx,all);
		}
		if(mx<=c)
			printf("Sequence %d\nFuse was not blown.\nMaximal power consumption was %d amperes.\n\n",k++,mx);
		else
			printf("Sequence %d\nFuse was blown.\n\n",k++);
	}
}