#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;

bool mystrcmp(char s1[],char s2[],int l){
	int i;
	for(i=0;i<l;i++)
		if(s1[i]!=s2[i])
			return false;
	return true;
}

void dpt(char s[],char s1[],char s2[],char c){
	int i,s1p=0,s2p=0,sl=strlen(s);
	for(i=0;i<sl && s[i]!=c;i++)
		s1[s1p++]=s[i];
	s1[s1p]=0;
	for(i++;i<sl;i++)
		s2[s2p++]=s[i];
	s2[s2p]=0;
}


int main(){
	int n,k=1;
	char ps[200],psa[200],psb[200];
	scanf("%d",&n);
	while(n--){
		int t;
		char now[200];
		scanf("%s",ps);
		dpt(ps,psa,psb,'#');
		int psal=strlen(psa),psbl=strlen(psb);
		scanf("%d",&t);
		printf("DATA SET #%d:\n",k++);
		while(t--){
			scanf("%s",now);
			int nl=strlen(now);
			if(nl>=psal+psbl && mystrcmp(now,psa,psal) && mystrcmp(now+(nl-psbl),psb,psbl))
				puts("POSSIBLE");
			else
				puts("IMPOSSIBLE");
		}
	}
}
