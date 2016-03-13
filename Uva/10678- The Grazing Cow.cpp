#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
#define pi (2*acos(0.0))
int main(){
	double n,a,b,x;
	scanf("%lf",&n);
	while(n--){
		scanf("%lf%lf",&a,&b);
		x=pi*(b/2)*sqrt((b/2)*(b/2)-(a/2)*(a/2));
		printf("%.3lf\n",x);
	}
}