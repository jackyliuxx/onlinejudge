#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int n,k=1,a[12],i,m;
	while(scanf("%d",&n),n!=-1){
		printf("Case %d:\n",k++);
		for(i=0;i<12;i++)
			scanf("%d",&a[i]);
		for(i=0;i<12;i++){
			scanf("%d",&m);
			if(m<=n)
				printf("No problem! :D\n"),n-=m;
			else
				printf("No problem. :(\n");
			n+=a[i];
		}
	}
}