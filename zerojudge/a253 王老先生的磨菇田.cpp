#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int n,m,a[110]={},i=2;
	while(i--){
		while(scanf("%d",&n),n!=-1){
			scanf("%d",&m);
			a[n]+=m;
		}
	}
	for(i=0;i<110;i++)
		if(a[i])
			printf("%d %d\n",i,a[i]);
}