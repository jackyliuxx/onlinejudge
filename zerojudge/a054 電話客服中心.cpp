#include<iostream>
#include<string>
using namespace std;
int main(){
	char n;
	int i,a;
	string s[10]={"BNZ","AMW","KLY","JVX","HU","GT","FS","ER","DOQ","CIP"};
	while(cin>>n){
		a=8*(n-'0');
		for(i=7;i>0;i--)
			cin>>n,a+=i*(n-'0');
		a%=10;
		cin>>n;
		cout<<s[(10-(n-'0')+10-a)%10]<<endl;
	}
}