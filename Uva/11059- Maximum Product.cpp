#include<iostream>
#include<stdio.h>
using namespace std;
long long a[18];
long long jacky(int x,int y){
	long long i,ans=1,f=1,l=1;
	if(x>y)
		return 0;
	if(x==y && a[x]<0)
		return 0;
	for(i=x;i<=y && f>0;i++)
		f*=a[i];
	for(i=y;i>=x && l>0;i--)
		l*=a[i];
	for(i=x;i<=y;i++)
		ans*=a[i];
	if(ans<0)
		ans/=(f>l?f:l);
	return ans;
}
int main(){
	int i,x;
	long long n,k=1,ans;
	while(scanf("%lld",&n)!=EOF){
		ans=0;
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		for(i=0,x=0;i<n;i++)
			if(a[i]==0)
				ans=max(ans,jacky(x,i-1)),x=i+1;
		ans=max(ans,jacky(x,i-1));
		printf("Case #%lld: The maximum product is %lld.\n\n",k++,ans);
	}
}