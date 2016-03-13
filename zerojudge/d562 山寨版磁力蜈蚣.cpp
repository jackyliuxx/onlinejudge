#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int n,a[100],i,j,x,y,p;
	while(cin>>n){
		for(i=0;i<n;i++)
			cin>>a[i];
		x=0,y=n-1;
		p=1;
		j=0;
		for(i=0;i<n;i++){
			while(j>=x && j<=y)
				printf("%d ",a[j]),j+=p;
			printf("\n");
			if(p>0)
				x++,j--;
			else
				y--,j++;
			p*=-1;
		}
	}
}