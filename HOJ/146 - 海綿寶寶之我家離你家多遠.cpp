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

struct edg{
	int to,cst;
}e[210000];
edg fts[20][210000];

struct home{
	vector<int> e;
	edg f;
	int lv;
	home(){}
}h[210000];

int n,mxl=0;

void bdftt(int x,int f,int nlv){
	int i;
	h[x].f.to=f;
	h[x].lv=nlv;
	for(i=0;i< h[x].e.size();i++){
		int nxe=h[x].e[i];
		if(e[nxe].to!=f)
			bdftt(e[nxe].to,x,nlv+1);
		else
			h[x].f.cst=e[nxe].cst;
	}
}

void bdfts(){
	while((1<<mxl)<n)
		mxl++;
	int i,j;
	for(i=0;i<n;i++)
		fts[0][i]=h[i].f;
	for(i=1;i<=mxl;i++){
		for(j=0;j<n;j++){
			fts[i][j].to=fts[i-1][fts[i-1][j].to].to;
			fts[i][j].cst=fts[i-1][fts[i-1][j].to].cst+fts[i-1][j].cst;
		}
	}
}

int dst(int fr,int to){
	int r=0,i;
	if( h[fr].lv > h[to].lv)
		swap(fr,to);
	i=mxl;
	while(h[fr].lv<h[to].lv){
		if(h[to].lv-h[fr].lv<(1<<i)){
			i--;
			continue;
		}
		r+=fts[i][to].cst;
		to=fts[i][to].to;
	}
	i=mxl;
	if(fr==to)
		return r;
	while(i>=0){
		if(fts[i][fr].to==fts[i][to].to){
			i--;
			continue;
		}
		r+=fts[i][fr].cst;
		r+=fts[i][to].cst;
		fr=fts[i][fr].to;
		to=fts[i][to].to;
	}
	r+=fts[0][fr].cst;
	r+=fts[0][to].cst;
	return r;
}


int main () {
	int q;
	int t,fr,to,cst,i;
	scanf("%d%d",&n,&q);
	for(i=0;i<n-1;i++){
		scanf("%d%d%d",&fr,&to,&cst);
		fr--;
		to--;
		e[i*2].to=to, e[i*2].cst=cst, h[fr].e.push_back(i*2);
		e[i*2+1].to=fr, e[i*2+1].cst=cst ,h[to].e.push_back(i*2+1);
	}
	bdftt(0,0,1);
	bdfts();
	for(i=0;i<q;i++){
		scanf("%d%d",&fr,&to);
		printf("%d\n",dst(fr-1,to-1));
	}
}
