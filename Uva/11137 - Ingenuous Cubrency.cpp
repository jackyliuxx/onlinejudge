#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	long long a[10010]={1},n,i,j,d[21];
	for(i=0;i<21;i++)
		d[i]=(i+1)*(i+1)*(i+1);
	for(i=0;i<21;i++)
		for(j=d[i];j<10010;j++)
			a[j]+=a[j-d[i]];
	while(~scanf("%lld",&n))
		printf("%lld\n",a[n]);
}
