#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	long long a,b,c,ans;
	while(~scanf("%lld%lld",&a,&b),a || b){
		ans=0;
		c=0;
		while(a || b){
			if(a%10+b%10+c>=10){
				ans++;
				c+=10;
			}
			a/=10;
			b/=10;
			c/=10;
		}
		if(ans==0)
			printf("No carry operation.\n");
		else if(ans==1)
			printf("1 carry operation.\n");
		else
			printf("%lld carry operations.\n",ans);
	}
}