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

int ff(int x,int *f){
	if(f[x]==x)
		return x;
	else
		return f[x]=ff(f[x],f);
}

int main () {
	int f[11000];
	int m,n,a,b;
	while(scanf("%d%d",&n,&m)!=EOF){
		int i,af,bf;
		for(i=0;i<=n;i++)
			f[i]=i;
		for(i=0;i<m;i++){
			scanf("%d%d",&a,&b);
			af=ff(a,f);
			bf=ff(b,f);
			if(af>bf)
				swap(af,bf);
			if(af!=bf)
				f[bf]=af;
		}
		scanf("%d",&a);
		printf("%d\n",ff(a,f));
	}
}
