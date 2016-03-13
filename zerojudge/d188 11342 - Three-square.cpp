#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int main(){
	int t,n,i,j,k,o;
	cin>>t;
	while(t--){
		scanf("%d",&n);
		o=0;
		for(i=0;i*i*3<=n;i++){
			for(j=i;j*j*2<=(n-i*i);j++){
				if(int(sqrt((double)n-i*i-j*j))*int(sqrt((double)n-i*i-j*j))==(n-i*i-j*j)){
					printf("%d %d %d\n",i,j,(int)sqrt((double)n-i*i-j*j));
					o=1;
					break;
				}
				if(o)
					break;
			}
			if(o)
				break;
		}
		if(o==0)
			printf("-1\n");
	}
}
