#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int k=1,t,n,now,next,i,a[1000],ap,l;
	scanf("%d",&t);
	while(t--){
		ap=l=0;
		scanf("%d",&n);
		for(now=n,next=0;1;now=next,next=0){
			a[ap++]=now;
			while(now)
				next+=(now%10)*(now%10),now/=10;
			if(next==1){
				printf("Case #%d: %d is a Happy number.\n",k++,n);
				break;
			}
			for(i=0;i<ap;i++){
				if(next==a[i]){
					printf("Case #%d: %d is an Unhappy number.\n",k++,n);
					l=1;
				}
			}
			if(l)
				break;			
		}
	}
}