#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	long long n,a[100]={1,1,2};
	for(int i=3;i<=80;i++)
		a[i]=a[i-1]+a[i-2];
	while(scanf("%lld",&n),n)
		printf("%lld\n",a[n]);
}