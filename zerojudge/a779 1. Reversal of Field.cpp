#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

int main(){
	string s,s2;
	while(getline(cin,s)){
		int i,j,ans=1;
		s2="";
		for(i=0,j=0;i<s.size();i++){
			if(s[i]>='a' && s[i]<='z')
				s2+=s[i];
			else if(s[i]>='A' && s[i]<='Z')
				s2+=s[i]-'A'+'a';
			else if(s[i]>='0' && s[i]<='9')
				s2+=s[i];
		}
		j=s2.size()-1;
		for(i=0;i<j;i++,j--){
			if(s2[i]!=s2[j]){
				ans=0;
				break;
			}
		}
		cout<<s<<endl;
		if(ans)
			puts("-- is a palindrome");
		else
			puts("-- is not a palindrome");
	}
}
/*
int main(){
	char s[1000],s2[1000];
	while(gets(s)){
		int i,j,ans=1;
		for(i=0,j=0;i<strlen(s);i++){
			if(s[i]>='a' && s[i]<='z')
				s2[j++]=s[i];
			else if(s[i]>='A' && s[i]<='Z')
				s2[j++]=s[i]-'A'+'a';
			else if(s[i]>='0' && s[i]<='9')
				s2[j++]=s[i];
		}
		s2[j]=0;
		j--;
		for(i=0;i<j;i++,j--){
			if(s2[i]!=s2[j]){
				ans=0;
				break;
			}
		}
		puts(s);
		if(ans)
			puts("-- is a palindrome");
		else
			puts("-- is not a palindrome");
	}
}
*/