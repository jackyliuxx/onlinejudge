#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main(){
	int n,i;
	string s1,s2;
	while(cin>>n){
		s1=s2="";
		while(n){
			if(n%2)
				s1+='1';
			else
				s1+='0';
			n/=2;
		}
		for(i=s1.size()-1;i>=0;i--)
			s2+=s1[i];
		cout<<s2<<endl;
	}
}