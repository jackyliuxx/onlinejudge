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

int a[3];
bool hs[110][110][110];

struct step {
	int a[3],st;
	step() {}
	step(int _a,int _b,int _c,int _st) {
		a[0]=_a;
		a[1]=_b;
		a[2]=_c;
		st=_st;
	}
};

queue<step> q;

int main () {
	while(cin>>a[0]>>a[1]>>a[2],a[0]||a[1]||a[2]) {
		memset(hs,0,sizeof(hs));
		while(q.size())
			q.pop();
		q.push(step(0,0,0,0));
		hs[0][0][0]=true;
		step nw;
		int ans=-1,na[3],nst,i,j;
		while(q.size()) {
			nw=q.front();
			q.pop();
			for(i=0; i<3; i++)
				na[i]=nw.a[i];
			nst=nw.st;
			if(na[2]==a[2]) {
				ans=nst;
				break;
			}
			if(!hs[a[0]][na[1]][na[2]]) {
				q.push(step(a[0],na[1],na[2],nst+1));
				hs[ a[0] ][ na[1] ][ na[2] ]=true;
			}
			if(!hs[na[0]][a[1]][na[2]]) {
				q.push(step(na[0],a[1],na[2],nst+1));
				hs[ na[0] ][ a[1] ][ na[2] ]=true;
			}
			if(!hs[0][na[1]][na[2]]) {
				q.push(step(0,na[1],na[2],nst+1));
				hs[ 0 ][ na[1] ][ na[2] ]=true;
			}
			if(!hs[na[0]][0][na[2]]) {
				q.push(step(na[0],0,na[2],nst+1));
				hs[ na[0] ][ 0 ][ na[2] ]=true;
			}
			if(na[0]<=a[1]-na[1]) {
				if(!hs[0][na[1]+na[0]][na[2]]) {
					q.push(step(0,na[1]+na[0],na[2],nst+1));
					hs[0][na[1]+na[0]][na[2]]=true;
				}
			}
			else if(!hs[na[0]-(a[1]-na[1])][a[1]][na[2]]) {
				q.push(step(na[0]-(a[1]-na[1]),a[1],na[2],nst+1));
				hs[na[0]-(a[1]-na[1])][a[1]][na[2]]=true;
			}
			if(na[1]<=a[0]-na[0]) {
				if(!hs[na[1]+na[0]][0][na[2]]) {
					q.push(step(na[1]+na[0],0,na[2],nst+1));
					hs[na[1]+na[0]][0][na[2]]=true;
				}
			}
			else if(!hs[a[0]][na[1]-(a[0]-na[0])][na[2]]) {
				q.push(step(a[0],na[1]-(a[0]-na[0]),na[2],nst+1));
				hs[a[0]][na[1]-(a[0]-na[0])][na[2]]=true;
			}
			if(na[0]+na[2]<=a[2] && !hs[0][na[1]][na[0]+na[2]]) {
				q.push(step(0,na[1],na[0]+na[2],nst+1));
				hs[0][na[1]][na[0]+na[2]]=true;
			}
			if(na[1]+na[2]<=a[2] && !hs[na[0]][0][na[1]+na[2]]) {
				q.push(step(na[0],0,na[1]+na[2],nst+1));
				hs[na[0]][0][na[1]+na[2]]=true;
			}
		}
		if(ans==-1)
			puts("No");
		else
			printf("%d\n",ans);
	}
}
