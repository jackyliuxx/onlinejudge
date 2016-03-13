#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	long long n,a,i;
	while(~scanf("%lld",&n)){
		for(i=1;n>i;i++)
			n-=i;
		i++;
		printf("%lld/%lld\n",i-n,n);
	}
}