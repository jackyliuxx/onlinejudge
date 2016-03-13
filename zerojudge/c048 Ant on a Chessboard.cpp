#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int n,i,j;
	while(scanf("%d",&n),n){
		for(i=1;i<n;i+=2)
			n-=i;
		i=(i+1)/2;
		if(i%2){
			if(n>i)
				printf("%d %d\n",i-(n-i),i);
			else
				printf("%d %d\n",i,n);
		}
		else{
			if(n>i)
				printf("%d %d\n",i,i-(n-i));
			else
				printf("%d %d\n",n,i);
		}
	}
}