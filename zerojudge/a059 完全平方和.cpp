#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int n,a,b,p=0,i,f;
	cin>>n;
	while(n--){
		f=0;
		scanf("%d %d",&a,&b);
		for(i=1;i<32;i++)
			if(i*i>=a && i*i<=b)
				f+=i*i;
		printf("Case %d: %d\n",++p,f);
	}
}