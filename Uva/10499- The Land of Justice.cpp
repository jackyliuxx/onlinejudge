#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	long long n;
	while(cin>>n,n>0){
		cout<<(n>=2)*(50+25*(n-2))<<"%\n";
	}
}
