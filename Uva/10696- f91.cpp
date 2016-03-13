#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	long long n,n2;
	while(~scanf("%lld",&n),n){
		n2=n;
		while(n<101){
			while(n<101)
				n+=11;
			n-=10;
		}
		printf("f91(%lld) = %lld\n",n2,n-10);
	}
}