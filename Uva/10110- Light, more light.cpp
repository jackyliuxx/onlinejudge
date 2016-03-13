#include<iostream>
#include<cmath>
using namespace std;
int main(){
	long long n,i,y;
	double x;
	while(cin>>n){
		if(n==0)
			continue;
		x=sqrt(double (n));
		y=x;
		if(y*y==n)
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
}