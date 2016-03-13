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

struct point {
	int x,y;
	bool operator<(const point &p2)const {
		if(x<p2.x)
			return true;
		if(x==p2.x && y<p2.y)
			return true;
		return false;
	}
	point(){}
	point(int _x,int _y){
		x=_x;
		y=_y;
	}
	point operator+(const point &p2)const{
		return point(x+p2.x,y+p2.y);
	}
};

point p[5140];
int r,c;
bool mp[5010][5010];

bool in(int x,int y) {
	if(x<=0 || x>r)
		return false;
	if(y<=0 || y>c)
		return false;
	return true;
}

int cnt(point np,point v){
	int r=1;
	point nxt=np+v;
	while(in(nxt.x,nxt.y)){
		if(!mp[nxt.x][nxt.y])
			return 0;
		nxt.x+=v.x;
		nxt.y+=v.y;
		r++;
	}
	return r;
}

int main () {
	int n;
	scanf("%d%d",&r,&c);
	scanf("%d",&n);
	int i,j;
	for(i=0; i<n; i++)
		scanf("%d%d",&p[i].x,&p[i].y);
	sort(p,p+n);
	memset(mp,0,sizeof(mp));
	for(i=0; i<n; i++) {
		mp[p[i].x][p[i].y]=true;
	}
	int mx=0;
	for(i=1; i<n; i++) {
		for(j=0; j<i; j++) {
			int vx=p[i].x-p[j].x,vy=p[i].y-p[j].y;
			if(!in(p[j].x-vx,p[j].y-vy))
				mx=max(mx,cnt(p[j],point(vx,vy)));
		}
	}
	if(mx<3)
		puts("0");
	else
		printf("%d\n",mx);
}
