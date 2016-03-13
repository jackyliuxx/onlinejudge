#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	char s[1000];
	while(gets(s)){
		int i;
		int sv=-1;
		int sl=strlen(s);
		for(i=0;i<sl && sv!=0;i++){
			if(s[i]=='('){
				if(sv==-1)
					sv=1;
				else
					sv++;
			}
			else if(s[i]==')')
				sv--;
		}
		int j;
		for(j=i+1;j<sl-1;j++)
			putchar(s[j]);
		putchar(' ');
		for(j=0;j<i;j++)
			putchar(s[j]);
		puts(";");
	}
}