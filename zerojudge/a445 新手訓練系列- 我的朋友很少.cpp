#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

int findad(int n,int *b) {
	if(b[n]==n)
		return n;
	b[n]=findad(b[n],b);
	return b[n];
}
int main () {
	int i,j,n,m,q,a[11000]= {},b[11000]= {},x,y,pppp;
	cin>>n>>m>>q;
	for(i=0;i<=n;i++)
		a[i]=b[i]=i;
	for(i=0;i<m;i++) {
		cin>>x>>y;
		pppp=min(findad(a[x],b),findad(a[y],b));
		b[b[a[x]]]=b[b[a[y]]]=pppp;
	}
	for(i=0; i<q; i++) {
		cin>>x>>y;
		a[x]=findad(a[x],b);
		a[y]=findad(a[y],b);
		if(a[x]==a[y])
			puts(":)");
		else
			puts(":(");
	}
}