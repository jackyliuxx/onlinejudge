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

int x[2110],y[2110],z[2110],ld[2110];

struct bomb{
	int dmg,a,b;
	bomb(int d,int x,int y){
		dmg=d;
		a=x;
		b=y;
	}
	bomb(){}
	bool operator<(const bomb& x)const{
		return dmg<x.dmg;
	}
};

vector<bomb> v;

int gdmg(int i,int j){
	return max(abs(x[i]-x[j]),max(abs(y[i]-y[j]),abs(z[i]-z[j])));
}

int ft(int a){
	if(ld[a]==a)
		return a;
	else
		return ld[a]=ft(ld[a]);
}

void link(int a,int b){
	ld[ft(b)]=ft(a);
}

int main () {
	int n,k;
	scanf("%d%d",&n,&k);
	int i,j;
	for(i=0;i<n;i++)
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
	for(i=1;i<n;i++)
		for(j=0;j<i;j++)
			v.push_back(bomb(gdmg(i,j),j,i));
	sort(v.begin(),v.end());
	for(i=0;i<n;i++)
		ld[i]=i;
	int lst=n;
	for(i=0;lst>k;i++){
		if(ft(v[i].a)!=ft(v[i].b)){
			link(v[i].a,v[i].b);
			lst--;
		}
	}
	while(ft(v[i].a)==ft(v[i].b))
		i++;
	printf("%d\n",v[i].dmg);
}
