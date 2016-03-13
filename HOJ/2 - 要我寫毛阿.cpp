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
#include <list>
#include <map>
using namespace std;

struct point{
	int v,n;
	point(){};
	point(int vv,int nn):v(vv),n(nn){}
	bool operator<(const point &p2)const{
		return v<p2.v;
	}
};

point p[210000];
int pp;

vector<int> stk;

int main () {
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int x,y;
		pp=0;
		while(n--){
			scanf("%d%d",&x,&y);
			p[pp].v=x;
			p[pp++].n=n;
			p[pp].v=y;
			p[pp++].n=n;
		}
		sort(p,p+pp);
		int i;
		stk.clear();
		for(i=0;i<pp;i++){
			if(stk.empty() || p[i].n!=stk.back())
				stk.push_back(p[i].n);
			else
				stk.pop_back();
		}
		if(stk.size())
			puts("N");
		else
			puts("Y");
	}
}
