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

int a[32][32],ans[10];

int happy(int x,int y) {
	int n=a[x][y];
	a[x][y]=0;
	int aans=1;
	if(a[x-1][y]==n)
		aans+=happy(x-1,y);
	if(a[x+1][y]==n)
		aans+=happy(x+1,y);
	if(a[x][y-1]==n)
		aans+=happy(x,y-1);
	if(a[x][y+1]==n)
		aans+=happy(x,y+1);
	return aans;
}

int main () {
	int n,m,q;
	while(cin>>n>>m) {
		int i,j;
		for(i=0; i<10; i++)
			ans[i]=0;
		for(i=0; i<=n+1; i++)
			a[i][0]=a[i][m+1]=0;
		for(j=0; j<=m+1; j++)
			a[0][j]=a[n+1][j]=0;
		for(i=1; i<=n; i++)
			for(j=1; j<=m; j++)
				cin>>a[i][j];
		for(i=1; i<=n; i++)
			for(j=1; j<=m; j++)
				if(a[i][j]) {
					int n=a[i][j];
					ans[n]=max(ans[n],happy(i,j));
				}
		cin>>q;
		int w;
		while(q--) {
			cin>>w;
			if(ans[w]>=2)
				cout<<ans[w]<<endl;
			else
				puts("0");
		}
	}
}
