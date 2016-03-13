#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
	long long n,i,j,i2,j2,k,ans,l;
	while(~scanf("%lld%lld",&i,&j)){
		i2=i;
		j2=j;
		if(i>j)
			swap(i,j);
		ans=0;
		for(k=i;k<=j;k++){
			l=1;
			for(n=k;n!=1; ){
				l++;
				if(n%2)
					n=3*n+1;
				else
					n=n/2;
			}
			if(l>ans)
				ans=l;
		}
		printf("%lld %lld %lld\n",i2,j2,ans);
	}
}