#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	unsigned long long n;
	while(~scanf("%llu",&n)){
		printf("%llu\n",(((1+n)*((n+1)/2))-1)*3-6);
	}
}