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
#define MAXN 110000
using namespace std;
map<int,int> m;
int main(){
	int x,mt=0,mn;
	while(scanf("%d",&x),x){
		int nb=++m[x];
		if(nb>mt)
			mt=nb,mn=x;
		else if(nb==mt && x<mn)
			mn=x;
		printf("%d %d\n",mt,mn);
	}
}



/*
int t[MAXN],lt[MAXN],rt[MAXN],hv[MAXN],nt[MAXN],*ft[MAXN],root=0,ctp=0;

inline int crt(int x,int *f){
	t[ctp]=x;
	lt[ctp]=-1;
	rt[ctp]=-1;
	nt[ctp]=1;
	hv[ctp]=1;
	ft[ctp]=f;
	ctp++;
	return ctp-1;
}

void lturn(int x){
}

void rturn(int x){
}

int ckt(int x,int np){
	int fin;
	if(t[root]==-1){
		crt(x,&root);
		return 1;
	}
	if(t[np]==x){
		nt[np]++;
		return nt[np];
	}
	if(x>t[np]){
		if(rt[np]!=-1)
			fin=ckt(x,rt[np]);
		else{
			rt[np]=crt(x,&rt[np]);
			fin=1;
		}
	}
	else{
		if(lt[np]!=-1)
			fin=ckt(x,lt[np]);
		else{
			lt[np]=crt(x,&lt[np]);
			fin=1;
		}
	}
	if(lt[np]!=-1 && rt[np]!=-1){
		if(hv[lt[np]]-hv[rt[np]]>1)
			rturn(np);
		else if(hv[rt[np]]-hv[lt[np]]>1)
			lturn(np);
		hv[np]=max(hv[rt[np]],hv[rt[np]])+1;
	}
	else if(lt[np]!=-1)
		hv[np]=hv[lt[np]]+1;
	else if(rt[np]!=-1)
		hv[np]=hv[rt[np]]+1;
	return fin;
}

int main () {
	int i,x,n,mt=0,mn;
	t[0]=-1,ft[0]=-1;
	while(scanf("%d",&n),n){
		scanf("%d",&x);
		int nb=ckt(x,root);
		if(nb>mt)
			mn=x;
		else if(nb==mt && x<mn)
			mn=x;
		printf("%d\n",mn);
	}
}
*/
