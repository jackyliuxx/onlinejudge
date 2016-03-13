#include<iostream> //NAC
#include<cstdio>
#include<cstring>
using namespace std;
int main() {
	char map[30][60];
	int n,x,y,z;
	while(cin>>n) {
		int i,j,sa[60],mx=0;
		for(i=0; i<30; i++)
			for(j=0; j<60; j++)
				map[i][j]=' ';
		for(i=0; i<60; i++)
			sa[i]=0;
		while(n--) {
			cin>>x>>y>>z;
			for(i=x; i<x+y+1; i++)
				sa[i]=max(sa[i],z+1);
			mx=max(mx,z+1);
		}
		sa[50]=sa[51]=0;
		sa[0]=0;
		for(i=0; i<51; i++) {
			if(i!=0 && sa[i]<sa[i-1] && sa[i]<sa[i+1])
				sa[i]=min(sa[i-1],sa[i+1]);
			if(i!=0 && sa[i]!=sa[i-1]) {
				int fr,to;
				fr=min(sa[i],sa[i-1]),to=max(sa[i],sa[i-1]);
				for(j=fr; j<=to; j++) {
					if(j==fr || j==to)
						map[j][i-1]='+';
					else
						map[j][i-1]='|';
				}
			}
			map[sa[i]][i]='-';
		}
		for(i=0; i<30; i++)
			map[i][50]=0;
		for(i=mx; i>=0; i--)
			puts(map[i]);
		puts("12345678901234567890123456789012345678901234567890");
	}
}
