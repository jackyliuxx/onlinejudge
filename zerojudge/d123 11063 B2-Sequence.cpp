#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	int n,b[200],k=1,i,j,a[10000],ans;
	while(~scanf("%d",&n)){
		ans=1;
		for(i=0;i<n;i++){
			scanf("%d",&b[i]);
			if(b[i]<1)
				ans=0;
		}
		sort(b,b+n);
		for(i=0;i<n-1;i++){
			if(b[i]==b[i+1]){
				ans=0;
				break;
			}
		}
		if(ans==0)
			printf("Case #%d: It is not a B2-Sequence.\n\n",k++);
		else{
			for(i=0;i<10000;i++)
				a[i]=-1;
			for(i=0;i<n-1;i++)
				for(j=i;j<n;j++)
					a[i*n+j]=b[i]+b[j];
			sort(a,a+n*n);
			for(i=0;i<n*n-1;i++){
				if(a[i]>0 && a[i]==a[i+1]){
					ans=0;
					break;
				}
			}
			if(ans)
				printf("Case #%d: It is a B2-Sequence.\n\n",k++);
			else
				printf("Case #%d: It is not a B2-Sequence.\n\n",k++);
		}
	}
}