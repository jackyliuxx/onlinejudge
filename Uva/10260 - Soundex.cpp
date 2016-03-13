#include<stdio.h>
#include<iostream>
using namespace std;
char s[]=" 1B1F1P1V2C2G2J2K2Q2X2S2Z3D3T4L5M5N6R";
int find(char ch){
	int i;
	for(i=1;i<37;i++)
		if(ch==s[i])
			return i;
	return 0;
}

int main(){
	char ch,b=' ';
	int a;
	while(cin.get(ch)){
		if(ch=='\n' || ch==' ')
			printf("%c",ch),b=' ';
		else{
			a=find(ch);
			if(a && s[a-1]!=b)
				printf("%c",s[a-1]);
			b=s[a-1];
		}
	}
}