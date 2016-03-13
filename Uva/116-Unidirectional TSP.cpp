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
#define lst(i) ((i+w-1)%w)
#define nxt(i) ((i+1)%w)
using namespace std;

inline int slct(int a,int b,int c,int p,int ml[][110]){
	if(a>b)
		swap(a,b);
	if(a>c)
		swap(a,c);
	if(b>c)
		swap(b,c);
	if(ml[a][p]<=ml[b][p] && ml[a][p]<=ml[c][p])
		return a;
	else if(ml[b][p]<=ml[a][p] && ml[b][p]<=ml[c][p])
		return b;
	else
		return c;
}

int main () {
	int w,l;
	int a[110][110];
	int ml[110][110];
	while(scanf("%d%d",&w,&l)!=EOF){
		int ans=2147483647;
		int i,j;
		for(i=0;i<w;i++)
			for(j=0;j<l;j++)
				scanf("%d",&a[i][j]);
		for(i=0;i<w;i++)
			ml[i][l-1]=a[i][l-1];
		for(j=l-2;j>=0;j--)
			for(i=0;i<w;i++)
				ml[i][j]=min(min(ml[lst(i)][j+1],ml[i][j+1]),ml[nxt(i)][j+1])+a[i][j];
		for(i=0;i<w;i++)
			ans=min(ans,ml[i][0]);
		int now;
		for(i=0;i<w;i++){
			if(ml[i][0]==ans){
				now=i;
				for(j=0;j<l;j++){
					if(j)
						putchar(' ');
					printf("%d",now+1);
					now=slct(lst(now),now,nxt(now),j+1,ml);
				}

				break;
			}
		}
		puts("");
		printf("%d\n",ans);
	}
}
