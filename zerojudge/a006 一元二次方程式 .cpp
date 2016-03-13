#include<iostream>
#include<cmath>
using namespace std;
int main(){
	double a,b,c,x,x2;
	while(cin>>a>>b>>c){
		x=(-b+sqrt((b*b)-4*a*c))/(2*a);
		x2=(-b-sqrt((b*b)-4*a*c))/(2*a);
		if(((b*b)-4*a*c)<0)
			cout<<"No real root\n";
		else if(((b*b)-4*a*c)==0)
			cout<<"Two same roots x="<<x<<endl;
		else
			cout<<"Two different roots x1="<< x <<" , x2="<< x2<<endl;
	}
}