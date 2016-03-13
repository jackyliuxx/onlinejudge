#include<iostream>               //¤£¤F¸Ñ
#include<cmath>
#include<stdio.h>
using namespace std;
int main(){
	long long i,n;
	double ans,x;
	while(cin>>n>>x,n){
		n%=360;
		x*=3.1415926/180;
		ans=cos(x/2)-cos((n*x)+x/2)/(2*sin(x/2));
		printf("%.4f\n",ans);
	}
}