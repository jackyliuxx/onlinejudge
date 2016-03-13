#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	long long a,l,n,i,k=1;
	while(scanf("%lld%lld",&a,&l),a>=0){
		n=a;
		i=1;
		do{
			if(n%2)
				n=3*n+1;
			else
				n/=2;
			i++;
		}while(n!=1 && n<=l);
		if(n>l)
			i--;
		printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n",k++,a,l,i);
	}
}