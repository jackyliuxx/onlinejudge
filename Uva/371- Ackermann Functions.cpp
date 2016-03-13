#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
	long long n,i,j,k,ans,l,m;
	while(~scanf("%lld%lld",&i,&j),i || j){
		if(i>j)
			swap(i,j);
		ans=0;
		for(k=i;k<=j;k++){

			l=1;
			n=k;
			do{
				l++;
				if(n%2)
					n=3*n+1;
				else
					n=n/2;
			}while(n!=1);
			if(l>ans)
				ans=l,m=k;
		}
		printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",i,j,m,ans-1);
	}
}