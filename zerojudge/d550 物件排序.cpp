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

int n,m;

struct obj {
	int n[300];
} a[11000];

bool cmp(obj x,obj y) {
	int i;
	for(i=0; i<m; i++){
		if(x.n[i]>y.n[i])
			return false;
		if(x.n[i]<y.n[i])
			return true;
	}
	return true;
}

int main () {
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
			scanf("%d",&a[i].n[j]);
	sort(a,a+n,cmp);
	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			if(j)
				putchar(' ');
			printf("%d",a[i].n[j]);
		}
		puts("");
	}
}
