#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <list>
#include <map>
using namespace std;

int findc(char *s,char c){
	int i,sl=strlen(s);
	for(i=0;i<sl;i++)
		if(s[i]==c)
			return i;
	return -1;
}

int main () {
	int t,i;
	char s[11000],c1,c2;
	scanf("%d",&t);
	while(t--){
		gets(s);
		gets(s);
		int sl=strlen(s);
		c1=getchar();
		c2=getchar();
		int p1,p2;
		p1=findc(s,c1);
		p2=findc(s,c2);
		if(p1>p2)
			swap(p1,p2);
		for(i=0;i<=p1;i++)
			putchar(s[i]);
		for(i=p2;i<sl;i++)
			putchar(s[i]);
		puts("");
		for(i=p1+1;i<p2;i++)
			putchar(s[i]);
		puts("");
	}
}
