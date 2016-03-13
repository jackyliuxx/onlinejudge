#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
int main(){
	string s;
	int i,deg,now,next;
	while(cin>>s,s!="0"){
		deg=1;
		now=0;
		for(i=0;i<s.size();i++)
			now+=s[i]-'0';
		while(now/10){
			next=0;
			while(now)
				next+=now%10,now/=10;
			now=next;
			deg++;
		}
		if(now==9){
			cout<<s;
			printf(" is a multiple of 9 and has 9-degree %d.\n",deg);
		}
		else{
			cout<<s;
			printf(" is not a multiple of 9.\n");
		}
	}
}