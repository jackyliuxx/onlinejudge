#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	long long n,i,j,p,a;
	long long k;
	while(cin>>n){
		p=a=0;
		k=1;
		for(i=1000000000;i>0;i/=10){
			if(n/i){
				p=1;
				j=n/i;
				n%=i;
			}
			else
				j=0;
			if(p){
				a+=j*k;
				k*=10;
			}
		}
		cout<<a<<endl;
	}
}