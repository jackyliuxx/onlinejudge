#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int n,a[60],i,b,ans,k=1;
	while(scanf("%d",&n),n){
		b=0;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
			b+=a[i];
		b/=n;
		ans=0;
		for(i=0;i<n;i++)
			if(a[i]>b)
				ans+=a[i]-b;
		printf("Set #%d\nThe minimum number of moves is %d.\n\n",k++,ans);
	}
}