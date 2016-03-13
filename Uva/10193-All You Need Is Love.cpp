#include<iostream>
#include<string>
using namespace std;
int gcd(int a,int b){
	int c;
	while(a){
		c=a;
		a=b%a;
		b=c;
	}
	return b;
}
int main(){
	int k=1,a,b,i,j,n;
	cin>>n;
	string s1,s2;
	while(n--){
		cin>>s1>>s2;
		a=b=0;
		for(i=1,j=s1.size()-1;j>=0;i*=2,j--)
			a+=i*(s1[j]=='1');
		for(i=1,j=s2.size()-1;j>=0;i*=2,j--)
			b+=i*(s2[j]=='1');
		if(gcd(a,b)!=1)
			cout<<"Pair #"<<k++<<": All you need is love!\n";
		else
			cout<<"Pair #"<<k++<<": Love is not all you need!\n";
	}
}