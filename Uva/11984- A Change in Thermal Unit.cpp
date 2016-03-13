#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int n,a,b,k=1;
	cin>>n;
	while(n--){
		cin>>a>>b;
		printf("Case %d: %.2lf\n",k++,a+b*5.0/9);
	}
}