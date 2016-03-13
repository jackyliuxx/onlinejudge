#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	long long a[30010]={1},k[11]={5,10,20,50,100,200,500,1000,2000,5000,10000};
	int n1,n2;
	for(int i=0;i<11;i++){
		for(int j=k[i];j<30010;j++){
			a[j]+=a[j-k[i]];
		}
	}
	while(scanf("%d.%d",&n1,&n2),n1+n2)
		printf("%3d.%02d%17lld\n",n1,n2,a[n1*100+n2]);
}
