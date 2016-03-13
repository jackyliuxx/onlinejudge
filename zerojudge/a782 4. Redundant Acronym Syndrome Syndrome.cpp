#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
	char s[1000];
	char theend[10]="END";
	theend[3]='\x1a';
	theend[4]=0;
	while(gets(s) && strcmp(s,"END")){
		int i,sl=strlen(s);
		int cs=-1;
		for(i=0;i<sl;i++){
			if(s[i]>='a' && s[i]<='z'){
				if(i==0 || s[i-1]==' '){
					cs=i;
					putchar(s[i]-'a'+'A');
				}
			}
		}
		putchar(' ');
		puts(s+cs);
	}
}