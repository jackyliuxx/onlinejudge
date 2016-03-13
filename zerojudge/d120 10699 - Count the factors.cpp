#include<iostream>
#include<stdio.h>
using namespace std;
int ispn(int n){
	int s,i;
	if(n==1)
		return 0;
	for(s=2;s*s<=n;s++)
		if(n%s==0)
			break;
	if(s*s>n)
		return 1;
	else
		return 0;
}
int main(){
	int n,ans,i;
	while(scanf("%d",&n),n){
		ans=0;
		for(i=1;i*i<=n;i++){
			if(n%i==0){
				ans+=ispn(i)+ispn(n/i);
				if(ispn(i) && i*i==n)
					ans--;
			}
		}
		printf("%d : %d\n",n,ans);
	}
}