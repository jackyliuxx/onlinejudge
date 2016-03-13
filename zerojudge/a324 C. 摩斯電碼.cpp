#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int main(){
	char c[26][10]={
		"---."		,"--...."	,".-..-"	,"-----",".--"	,"..-.-"	,"--..--"	,"-...",
		"-.--"		,"..-..-.--","..-..--"	,"----.","..---","-.-."		,"--.-"		,"--...-",
		"..-..-..-"	,".-.-"		,"-..-"		,"..."	,".-...","..-..."	,"..--."	,"..-..-.-.",
		"--..-."	,"..-..-..."}
	;
	int n,i,j;
	char s[210];
	scanf("%d",&n);
	gets(s);
	while(n--){
		int p=0;
		char s3[210]={};
		gets(s);
		for(i=0;i<strlen(s);i++){
			char s2[210]={};
			int l=0;
			if(s[i]==' ')
				s3[p++]=' ';
			else {
				while(i<strlen(s) && s[i]!=' '){
					s2[l++]=s[i++];
					for(j=0;j<26;j++){
						if(strcmp(s2,c[j])==0){
							s3[p++]=j+'A';
							for(int k=0;k<l;k++)
								s2[k]=0;
							l=0;
							break;
						}
					}
				}
				i--;
			}
		}
		puts(s3);
	}
}