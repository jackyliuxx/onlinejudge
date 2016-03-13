#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int a,b,i,j,k,kk=0,l,m,n,o,m2,ans[20]={};
	for(i=1;i<1000000;i++){
		m=n=m2=0;
		k=i;
		if(i>99999)
			l=6;
		else if(i>9999)
			l=5;
		else if(i>999)
			l=4;
		else if(i>99)
			l=3;
		else if(i>9)
			l=2;
		else 
			l=1;
		for(j=100000;j>0;j/=10){
			m=k/j;
			k%=j;
			m2=m;
			for(o=1;o<l;o++)
				m2*=m;
			n+=m2;
		}
		if (n==i)
			ans[kk++]=i;
	}
	while(cin>>a>>b){
		k=0;
		for(i=0;i<20;i++){
			if(ans[i]>=a && ans[i]<=b){
				printf("%d ",ans[i]);
				k=1;
			}
		}
		if(k==0)
			printf("none");
		cout<<endl;
	}
}
