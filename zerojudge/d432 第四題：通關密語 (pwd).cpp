#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
void ans(string s1,string s2){
	if(s1.size()==0)
		return;
	printf("%c",s2[s2.size()-1]);
	int i;
	for(i=0;i<s1.size();i++)
		if(s1[i]==s2[s2.size()-1])
			break;
	ans(s1.substr(0,i),s2.substr(0,i));
	ans(s1.substr(i+1,s1.size()-i-1),s2.substr(i,s2.size()-i-1));
}
int main(){
	string s1,s2;
	cin>>s1>>s2;
	ans(s1,s2);
}