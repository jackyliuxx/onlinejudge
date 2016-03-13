#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	long long m[80]={0},w[80]={1},n;
	for(int i=1;i<80;i++)
		w[i]=m[i-1]+1,m[i]=m[i-1]+w[i-1];
	while(scanf("%lld",&n),n>=0)
		printf("%lld %lld\n",m[n],m[n]+w[n]);
}

