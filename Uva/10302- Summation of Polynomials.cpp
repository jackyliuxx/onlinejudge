#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	long long n,ans;
	while(~scanf("%lld",&n)){
		ans=0;
		for(long long i=1;i<=n;i++)
			ans+=i*i*i;
		printf("%lld\n",ans);
	}
}