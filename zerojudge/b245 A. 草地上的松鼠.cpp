#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	int t,n,i,a[100000],ans,m;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		m=0;
		for(i=0;i<n-1;i++)
			if(a[i+1]-a[i]>m)
				m=a[i+1]-a[i],ans=i+1;
		printf("%d\n",ans);
	}
}