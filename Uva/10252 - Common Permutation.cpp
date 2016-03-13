#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main(){
	int i;
	int a[30],b[30];
	string s1,s2;
	while(getline(cin,s1)){
		getline(cin,s2);
		for(i=0;i<30;i++)
			a[i]=b[i]=0;
		for(i=0;i<s1.size();i++)
			a[s1[i]-'a']++;
		for(i=0;i<s2.size();i++)
			b[s2[i]-'a']++;
		for(i=0;i<30;){
			if(a[i] && b[i])
				printf("%c",i+'a'),a[i]--,b[i]--;
			else
				i++;
		}
		printf("\n");
	}
}