#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main(){
	string s1,s2,s3;
	int i,j,n,g,k;
	while(cin>>s1){
		for(i=1;i<=10000;i++){
			g=0;
			s2="";
			for(j=s1.size()-1;j>=0;j--){
				n=i+s1[j]-'A';
				while(n)
					s2+=n%10,n/=10;
			}
			for(k=0;k<s2.size()-3;k++){
				for(j=0;j<s2.size()-1;j++)
					s2[j]=(s2[j]+s2[j+1])%10;
			}
			if(s2[0]==0 && s2[1]==0 && s2[2]==1){
				g=i;
				break;
			}
		}
		if(g)
			printf("%d\n",g);
		else
			printf(":(\n");
	}
}