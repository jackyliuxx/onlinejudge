#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
	long long n,m,a,i;
	while(cin>>n){
		a=0;
		m=1;
		for(i=0;i<n;i++){
			m+=i*(i+1)/2+1;
		}
		cout<<m<<endl;
	}
}