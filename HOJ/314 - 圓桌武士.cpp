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

int n;

struct ads{
	int dst,s;
	ads(){}
	ads(int x,int y):dst(x),s(y){}
};

int hs[2110000];
vector<int> s[2110000],d[2110000];
vector<ads> av;

void pd(int x){
	if(s[x].size()==0)
		return;
	int i,j;
	for(i=j=0;i<s[x].size();i++){
		while(j<d[x].size() && d[x][j]<s[x][i])
			j++;
		int f,l;
		if(j==0)
			f=d[x].back()-n;
		else
			f=d[x][j-1];
		if(j==d[x].size())
			l=d[x][0]+n;
		else
			l=d[x][j];
		av.push_back(ads(f-s[x][i],s[x][i]));
		av.push_back(ads(l-s[x][i],s[x][i]));
	}
}

bool adss(ads x,ads y){
	return x.dst<y.dst;
}

int cdst(int x,int y){
	if((long long)x*y>=0)
		return max(abs(x),abs(y));
	else
		return abs(x)+abs(y)+min(abs(x),abs(y));
}

int getans(){
	int r=999999999;
	int i,j,nhs=0;
	for(i=0,j=0;j<av.size();j++){
		if(hs[av[j].s]==0)
			nhs++;
		hs[av[j].s]++;
		while(hs[av[i].s]>1){
			hs[av[i].s]--;
			i++;
		}
		if(nhs==n)
			r=min(r,cdst(av[i].dst,av[j].dst));
	}
	return r;
}

int main () {
	scanf("%d",&n);
	int i,x;
	for(i=0;i<=n;i++)
		s[i].clear(),d[i].clear();

	for(i=0;i<n;i++){
		scanf("%d",&x);
		s[x].push_back(i);
	}
	for(i=0;i<n;i++){
		scanf("%d",&x);
		d[x].push_back(i);
	}
	av.clear();
	memset(hs,0,sizeof(hs));
	for(i=1;i<=n;i++){
		pd(i);
	}
	sort(av.begin(),av.end(),adss);
	printf("%d\n",getans());
}
