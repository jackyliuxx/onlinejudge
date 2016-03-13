#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
char s[1000010];
int main(){
	int n,i,ans;
	while(gets(s),strcmp(s,"END")){
		n=strlen(s);
		if(n==1 && strcmp(s,"1")==0)
			printf("1\n");
		else{
			for(ans=1;n!=1;ans++){
				i=0;
				while(n!=0){
					n/=10;
					i++;
				}
				n=i;
			}
			printf("%d\n",ans+1);
		}
	}
}