#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	char s[20];
	int t,n,h,i;
	cin>>t;
	while(t--){
		cin>>n>>h;
		for(i=0;i<n-h;i++)
			s[i]='0';
		for(i=n-h;i<n;i++)
			s[i]='1';
		do{
			for(i=0;i<n;i++)
				printf("%c",s[i]);
			cout<<endl;
		}while(next_permutation(s,s+n));
		if(t!=0)
			cout<<endl;
	}
}