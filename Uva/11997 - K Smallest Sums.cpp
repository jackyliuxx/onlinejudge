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

int a[800][800],k;

struct haha{
	int t,y;
	bool operator<(const haha &x)const{
		return t>x.t;
	}
};

void mix(int x[],int y[]){
	int i;
	priority_queue<haha> pq;
	haha nx;
	for(i=0;i<k;i++){
		nx.t=x[i]+y[0];
		nx.y=0;
		pq.push(nx);
	}
	for(i=0;i<k;i++){
		nx=pq.top();
		pq.pop();
		x[i]=nx.t;
		nx.t+=-y[nx.y]+y[nx.y+1];
		nx.y++;
		pq.push(nx);
	}
}

int main () {
	while(scanf("%d",&k)!=EOF) {
		int i,j;
		for(i=0; i<k; i++) {
			for(j=0; j<k; j++)
				scanf("%d",&a[i][j]);
			sort(a[i],a[i]+k);
		}
		for(i=1;i<k;i++){
			mix(a[0],a[i]);
		}
		for(i=0;i<k;i++){
			if(i)
				putchar(' ');
			printf("%d",a[0][i]);
		}
		puts("");
	}
}
