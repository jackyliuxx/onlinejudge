#include<iostream>
#include<string>
using namespace std;
int main (){
	int n,i,f;
	string a;
	cin>>n;
	while(n--){
		f=1;
		cin>>a;
		for(i=0;i<a.size();i++)
			f*=a[i]-'0';
		cout<<f<<endl;
	}
}