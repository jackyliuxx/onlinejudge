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
#define NE (2147483647)

struct edg{
	int to,cst;
	edg(){}
	edg(int _to,int _cst):to(_to),cst(_cst){}
};

int n,m;
vector<edg> e[514];
int d[514][2];

int sp(int fr,int to){
	int i;
	for(i=0;i<=n;i++)
		d[i][0]=NE,d[i][1]=0;
	d[fr][0]=0;
	queue<int> q;
	bool inq[514]={};
	while(q.size())
		q.pop();
	q.push(fr);
	while(q.size()){
		int x=q.front();
		q.pop();
		inq[x]=false;
		for(i=0;i < e[x].size();i++){
			edg ne=e[x][i];
			if(d[ne.to][0]>d[x][0]+ne.cst){
				d[ne.to][0]=d[x][0]+ne.cst;
				d[ne.to][1]=d[x][1]+1;
				if(d[ne.to][1]>n-1){
					if(ne.to==to)
						return NE;
					else
						inq[x]=true;
				}
				if(!inq[ne.to]){
					q.push(ne.to);
//					inq[x]=true;
				}
			}
		}
	}
	return d[to][0];
}

int main () {
	scanf("%d%d",&n,&m);
	int i,x,y,z;
	for(i=0;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		e[x].push_back(edg(y,z));
	}
	int ans=sp(1,n);
	if(ans==NE)
		puts("QAQ");
	else
		printf("%d\n",ans);
}
