#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	int a[3][3],i,j,b[3]={0,1,2},ans,all,now,an[3];
	char c[3]={'B','C','G'};
	while(~scanf("%d%d%d",&a[0][0],&a[0][2],&a[0][1])){
		ans=0;
		all=0;
		for(i=1;i<3;i++)
			scanf("%d%d%d",&a[i][0],&a[i][2],&a[i][1]);
		for(i=0;i<3;i++)
			for(j=0;j<3;j++)
				all+=a[i][j];
		do{
			now=0;
			for(i=0;i<3;i++)
				now+=a[i][b[i]];
			if(now>ans){
				for(i=0;i<3;i++)
					an[i]=b[i];
				ans=now;
			}
		}while(next_permutation(b,b+3));
		for(i=0;i<3;i++)
			printf("%c",c[an[i]]);
		printf(" %d\n",all-ans);
	}
}