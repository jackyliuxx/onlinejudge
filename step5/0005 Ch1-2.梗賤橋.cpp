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

bool isprime[1001000];

void doch(int *plc,int n,int pn) {
	int i;
	for(i=pn+pn; i<=n; i+=pn)
		swap(plc[pn],plc[i]),isprime[i]=false;
}

void godo(int *plc,int n) {
	int i;
	for(i=2; i<=n; i++)
		if(isprime[i])
			doch(plc,n,i);
}

int main () {
	static int plc[1001000],fnp[1001000];
	int t,n,m,i;
	scanf("%d",&t);
	for(i=2;i<1001000;i++)
		isprime[i]=true;
	for(i=1; i<=1000100; i++)
		plc[i]=i;
	godo(plc,1000100);
	for(i=1;i<=1000100;i++)
		fnp[plc[i]]=i;
	while(t--) {
		scanf("%d%d",&n,&m);
		if(isprime[fnp[m]] || fnp[m]>n)
			puts("Geng Jian malheureux roi mauvaise!!");
		else
			printf("%d\n",fnp[m]);
	}
}
