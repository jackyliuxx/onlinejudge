#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int t,n,p,a[2][1010],x,i;
	scanf("%d",&t);
	while(t--){
		a[0][0]=a[1][0]=1;
		for(i=1;i<=1000;i++)
			a[0][i]=a[1][i]=0;
		scanf("%d%d",&n,&p);
		while(p--){
			scanf("%d",&x);
			for(i=0;i<=1000-x;i++){
				if(a[0][i])
					a[1][i+x]++;
			}
			for(i=0;i<=1000;i++)
				a[0][i]=a[1][i];
		}
		if(a[0][n])
			printf("YES\n");
		else
			printf("NO\n");		
	}
}