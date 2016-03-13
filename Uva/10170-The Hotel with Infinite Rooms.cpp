#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	long long s,d,i;
	while(scanf("%lld%lld",&s,&d)!=EOF){
		for(i=s;i<d;i++)
			d-=i;
		printf("%lld\n",i);
	}
}