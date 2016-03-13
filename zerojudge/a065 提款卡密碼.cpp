#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int abs(int a){
	if(a<0)
		a=0-a;
	return a;
}
int main(){
	string a,b;
	int i;
	while(cin>>a){
		b="";
		for(i=0;i<6;i++)
			b+=('0'+abs(a[i]-a[i+1]));
		cout<<b<<endl;
	}
}