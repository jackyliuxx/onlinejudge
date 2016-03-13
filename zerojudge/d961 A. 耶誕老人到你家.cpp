#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	int t,n,m,ans,i,j,a[50000],b[50000];
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<m;i++)
			scanf("%d",&b[i]);
		sort(a,a+n);
		sort(b,b+m);
		for(i=0,j=0;i<n && j<m;j++){
			if(a[i]<=b[j]){
				ans++;
				i++;
			}
		}
		if(ans)
			printf("%d\n",ans);
		else
			printf("Santa Claus wishes you get AC in the next submission.\n");
	}
}