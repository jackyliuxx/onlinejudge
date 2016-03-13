#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	long long n=0,a=0;
	int c;
	while(~(c=getchar())){
		if(c=='\n'){
			n+=a;
			a=0;
			printf("%lld\n",n);
			n=0;
		}
		else if(c==' '){
			n+=a;
			a=0;
		}
		else
			a=(a<<3)+(a<<1)+c-'0';
	}
}