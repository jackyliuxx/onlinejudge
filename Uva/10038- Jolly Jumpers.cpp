#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main(){
	long long i,n,a[3000],k,b[3000];
	while(~scanf("%lld",&n)){
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		for(i=0;i<n;i++)
			b[i]=0;
		k=1;
		for(i=1;i<n;i++){
			if(abs(a[i]-a[i-1])>n-1){
				k=0;
				break;}
			else
				b[abs(a[i]-a[i-1])]++;
		}
		for(i=1;i<n;i++)
			if(b[i]==0)
				k=0;
		if(k)
			printf("Jolly\n");
		else
			printf("Not jolly\n");
	}
}