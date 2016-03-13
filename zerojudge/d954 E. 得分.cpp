#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int n,s,i,x,t;
	long long a[10100];
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&s);
		for(i=0;i<10100;i++)
			a[i]=0;
		while(n--){
			scanf("%d",&x);
			a[x]++;
			for(i=x+1;i<10001;i++)
				a[i]+=a[i-x];
		}
		printf("%lld\n",a[s]);
	}
}