#include<iostream>
#include<string>
using namespace std;
int main(){
	int n,t;
	char ch;
	string s;
	int a1,a2,b1,b2,s1,s2,ta,tb;
	cin>>t;
	while(t--){
		cin>>n;
		cin>>a1>>ch>>a2>>b1>>ch>>b2;
		while(n--){
			cin>>s>>s1>>ch>>s2;
			ta=(a1-s1)*60+a2-s2;
			tb=(b1-s1)*60+b2-s2;
			cout<<(ta/60<10 ? "0" : "")<<ta/60<<ch<<(ta%60<10 ? "0" : "")<<ta%60<<' '<<(tb/60<10 ? "0" : "")<<tb/60<<ch<<(tb%60<10 ? "0" : "")<<tb%60<<endl;
		}
	}
}