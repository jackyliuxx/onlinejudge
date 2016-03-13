#include<bits/stdc++.h>
using namespace std;

bool trytry(char s[],int x,int n){
	char c;
	if(x<n/2)
		c=s[n-1-x];
	else if(x>n/2)
		c=s[n-x];
	else
		c='a';
	char s2[20];
	strcpy(s2,s);
	s2[x]=c;
	s2[x+1]=0;
	strcat(s2,s+x);
	for(int i=0;i<=n;i++)
		if(s2[i]!=s2[n-i])
			return false;
	puts(s2);
	return true;
}

int main(){
	char s[100];
	scanf("%s",s);
	int n=strlen(s);
	int i;
	for(i=0;i<=n;i++)
		if(trytry(s,i,n))
			break;
	if(i>n)
		puts("NA");
}

