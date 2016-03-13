#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int n,a[66]={1,1};
	for(int i=2;i<66;i++)
		a[i]=a[i-1]+a[i-2];
	while(~scanf("%d",&n)){
		printf("%d\n",a[n]);
	}
}