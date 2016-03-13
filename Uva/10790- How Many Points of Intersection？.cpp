#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	unsigned long long a,b,ans,k=1;
	while(scanf("%lld%lld",&a,&b),a || b){
		ans=0;
		for(int i=0;i<b;i++){
			ans+=i*(a*(a-1)/2);
		}
		printf("Case %lld: %lld\n",k++,ans);
	}
}