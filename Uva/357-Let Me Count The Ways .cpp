#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	long long a[30010]={1},n,i,j,d[5]={1,5,10,25,50};
	for(i=0;i<5;i++)
		for(j=d[i];j<30010;j++)
			a[j]+=a[j-d[i]];
	while(~scanf("%lld",&n)){
		if(a[n]==1)
			printf("There is only 1 way to produce %lld cents change.\n",n);
		else
			printf("There are %lld ways to produce %lld cents change.\n",a[n],n);
	}
}
