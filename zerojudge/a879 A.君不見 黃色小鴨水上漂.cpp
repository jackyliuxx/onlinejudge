//by jackyliuxx
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
using namespace std;

struct pt{
	int x,y;
};

inline int dts(pt a,pt b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int main () {
	int t;
	scanf("%d",&t);
	pt p[5140],v;
	while(t--){
		int n,s;
		scanf("%d%d",&n,&s);
		s*=s;
		int ans=0;
		int i;
		for(i=0;i<n;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		scanf("%d%d",&v.x,&v.y);
		for(i=0;i<n;i++)
			if(dts(p[i],v)<=s)
				ans++;
		printf("%d\n",ans);
	}
}
