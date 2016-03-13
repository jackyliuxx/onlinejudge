#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	long long n,n2;
	int i;
	while(~scanf("%lld",&n)){
		n2=n;
		for(i=1;n>i;i++)
			n-=i;
		i++;
		cout<<"TERM "<<n2<<" IS "<<n<<"/"<<i-n<<"\n";
	}
}