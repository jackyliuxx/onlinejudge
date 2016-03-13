#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;
#define MAXN 10010
int a[MAXN],b[MAXN],x[MAXN],y[MAXN],fi[MAXN],n;
int LIS(){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(x[j]>=a[i]){
				x[j]=a[i],fi[i]=min(j+1,fi[i]);
				break;
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(y[j]>=b[i]){
				y[j]=b[i],fi[n-i-1]=min(j+1,fi[n-i-1]);
				break;
			}
		}
	}
	return 0;
}
		
int main(){
	int i,j,ans;
	while(cin>>n){
		for(i=0;i<n;i++)
			x[i]=y[i]=99999999,fi[i]=999999;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=n-1;i>=0;i--)
			b[i]=a[n-i-1];
		ans=0;
		LIS();
		for(i=0;i<n;i++)
			ans=max(ans,fi[i]);
		printf("%d\n",ans*2-1);
	}
}