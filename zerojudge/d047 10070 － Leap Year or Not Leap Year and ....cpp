#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int what(string s,int n){
	int i,m;
	m=0;
	for(i=0;i<s.size();i++){
		m*=10;
		m+=s[i]-'0';
		m%=n;
	}
	if(m)
		return 0;
	else
		return 1;
}
int main(){
	int i,k,lp,hp,bp;
	string s;
	while(cin>>s){
		k=1;
		lp=what(s,4)-what(s,100)+what(s,400);
		hp=what(s,15);
		bp=what(s,55)+lp-1;
		if(lp)
			printf("This is leap year.\n"),k=0;
		if(hp)
			printf("This is huluculu festival year.\n"),k=0;
		if(bp==1)
			printf("This is bulukulu festival year.\n"),k=0;
		if(k)
			printf("This is an ordinary year.\n");
		printf("\n");
	}
}