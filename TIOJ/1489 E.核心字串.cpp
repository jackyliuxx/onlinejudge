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
using namespace std;

int main () {
	int sl,ch[26];
	static char s[1001000];
	while(scanf("%d",&sl),sl){
		gets(s);
		gets(s);
		int i,j;
		for(i=0;i<26;i++)
			ch[i]=0;
		int ys=0;
		for(i=0;i<sl && ys<26;i++){
			if(ch[s[i]-'a']==0)
				ys++;
			ch[s[i]-'a']++;
		}
		if(ys<26)
			puts("not found");
		else{
			int sb=0,se=sl;
			i--;
			ch[s[i]-'a']--;
			for(j=0;i<sl;i++){
				ch[s[i]-'a']++;
				while(ch[s[j]-'a']>1){
					ch[s[j]-'a']--;
					j++;
				}
				if(i+1-j<se-sb)
					se=i+1,sb=j;
			}
			for(i=sb;i<se;i++)
				putchar(s[i]);
			puts("");
		}
	}
}
