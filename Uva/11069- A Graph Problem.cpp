#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int i;
	long long n,a[80][3]={{},{1,0,0,},{1,1,0}};
	for(i=3;i<=76;i++){
		a[i][0]=a[i-1][1]+a[i-1][2];
		a[i][1]=a[i-1][0];
		a[i][2]=a[i-1][1];
	}
	while(cin>>n)
		cout<<a[n][0]+a[n][1]<<endl;
}
