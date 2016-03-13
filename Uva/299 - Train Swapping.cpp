#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int t,n,a[60],i,j,n1,n2,ans;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		n1=n-1;
		ans=0;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n-1;i++,n1--)
			for(j=0;j<n1;j++)
				if(a[j]>a[j+1])
					swap(a[j],a[j+1]),ans++;
		printf("Optimal train swapping takes %d swaps.\n",ans);
	}
}