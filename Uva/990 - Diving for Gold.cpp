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
struct location {
	int gold,p,d[35],v[35];
} a[1010];

int main () {
	int t,w,n,d,v,i,j,k,fg,fi,g=0;
	while(cin>>t>>w) {
		w*=3;
		for(i=0; i<1010; i++)
			a[i].p=-1,a[i].gold=-1;
		a[0].p=a[0].gold=0;
		cin>>n;
		for(i=0; i<n; i++) {
			cin>>d>>v;
			for(j=1010-d*w; j>=0; j--) {
				if(a[j].p!=-1 && (a[j+d*w].p==-1 || a[j+d*w].gold < a[j].gold+v)) {
					for(k=0 ; k < a[j].p ; k++) {
						a[j+d*w].d[k]=a[j].d[k];
						a[j+d*w].v[k]=a[j].v[k];
					}
					a[j+d*w].gold=a[j].gold+v;
					a[j+d*w].d[k]=d;
					a[j+d*w].v[k]=v;
					k++;
					a[j+d*w].p=k;
				}
			}
		}
		fg=-1;
		for(i=0; i<=t; i++)
			if( a[i].gold > fg )
				fg=a[i].gold,fi=i;
		if(g)
			puts("");
		printf("%d\n%d\n",a[fi].gold,a[fi].p);
		for(i=0; i<a[fi].p; i++)
			printf("%d %d\n",a[fi].d[i],a[fi].v[i]);
		g++;
	}
}
