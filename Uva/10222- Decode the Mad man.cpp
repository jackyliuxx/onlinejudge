#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main(){
	string s="`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
	char ch;
	while(cin.get(ch)){
		if(ch==' ' || ch =='\n')
			printf("%c",ch);
		else
			printf("%c",s[s.find(ch)-2]);
	}
}