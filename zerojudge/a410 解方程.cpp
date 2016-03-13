#include<iostream>                   //NA
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	double a,b,c,d,e,f,ansx,ansy;
	int i,j,n;
	cin>>a>>b>>c>>d>>e>>f;
	if(b*d==e*a && c*d==f*a)
		cout<<"Too many\n";
	else if(b*d==e*a && c*d!=f*a)
		cout<<"No answer\n";
	else{
		printf("x=%.2lf\n",(e*c-b*f)/(a*e-b*d));
		printf("y=%.2lf\n",(a*f-d*c)/(a*e-b*d));
	}
}
