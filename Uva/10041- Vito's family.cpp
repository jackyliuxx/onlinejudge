#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int main(){
	int n,m,i,a[500],ans,p;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&m);
		for(i=0;i<m;i++)
			scanf("%d",&a[i]);
		sort(a,a+m);
		p=a[m/2];
		ans=0;
		for(i=0;i<m;i++)
			ans+=abs(a[i]-p);
		printf("%d\n",ans);
	}
}