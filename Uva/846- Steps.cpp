#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int n,a,b,i;
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&a,&b);
		a=b-a;
		for(i=1;a>i;i++)
			a-=i*2;
		i--;
		i*=2;
		i+=(a>0);
		printf("%d\n",i);
	}
}