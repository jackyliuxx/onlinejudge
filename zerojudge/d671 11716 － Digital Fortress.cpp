#include<iostream>
#include<stdio.h>
#include<cmath>
#include<string>
using namespace std;
int main(){
	string s;
	int t,i,ss,j;
	scanf("%d",&t);
	cin>>ws;
	while(t--){
		getline(cin,s);
		ss=int(sqrt(double(s.size())));
		if(ss*ss!=s.size())
			printf("INVALID\n");
		else{
			for(i=0;i<ss;i++)
				for(j=i;j<s.size();j+=ss)
					printf("%c",s[j]);
			printf("\n");
		}
	}
}