#include<bits/stdc++.h>
using namespace std;

struct road{
	int d,x,y,xsz;
	road(){}
	road(int _x,int _y,int _d):x(_x),y(_y),d(_d){}
};

long long C(long long a,long long b){
	if(b>a)
		return 0;
	long long r=1;
	for(int i=0;i<b;i++){
		r*=(a-i);
		r/=(i+1);
	}
	return r;
}

vector<int> ed[110000];
road rd[110000];
double tt;
int n;

inline long long cdd(road r){
	return 2*r.d*(C(r.xsz,2)*(n-r.xsz)+C(n-r.xsz,2)*r.xsz);
}

int fd(int x,int y){
	int rt=1;
	for(int i=0;i<ed[x].size();i++){
		road &r=rd[ed[x][i]];
		int nxt=(r.x==x ? r.y : r.x);
		if(nxt==y)
			continue;
		r.xsz=fd(nxt,x);
		tt+=cdd(r);
		rt+=r.xsz;
	}
	return rt;
}

int main(){
	tt=0;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(a>b)
			swap(a,b);
		rd[i]=road(a,b,c);
		ed[a].push_back(i);
		ed[b].push_back(i);
	}
	rd[0].xsz=fd(rd[0].x,rd[0].y);
	fd(rd[0].y,rd[0].x);
	tt+=cdd(rd[0]);
	int q;
	scanf("%d",&q);
	while(q--){
		int x,nn;
		scanf("%d%d",&x,&nn);
		x--;
		road r=rd[x];
		r.d-=nn;
		tt-=cdd(r);
		rd[x].d=nn;
		printf("%.10f\n",tt/C(n,3));
	}
}
