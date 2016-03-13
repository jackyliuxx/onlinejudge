#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main(){
	int ans,i,n;
	string s;
	while(cin>>s,s!="0"){
		ans=0;
		for(i=s.size()-1,n=2;i>=0;i--,n*=2)
			ans+=(s[i]-'0')*(n-1);
		printf("%d\n",ans);
	}
}