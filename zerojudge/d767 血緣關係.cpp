#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

int tree[101000][3]={};
vector<int> son[101000];

int level(int x){
	int i;
	for(i=0;i<son[x].size();i++){
		tree[son[x][i]][2]=tree[x][2]+1;
		level(son[x][i]);
	}
	return 0;
}

int ans(int x,int y) {
	int r=0;
	while(x!=y) {
		if(tree[x][2]>tree[y][2]) {
			r++;
			x=tree[x][0];
		}
		else {
			r++;
			y=tree[y][0];
		}
	}
	printf("%d %d\n",x,r);
	return r;
}

int main () {
	int n,q,i,t,x,y;
	scanf("%d%d",&n,&q);
	tree[0][0]=tree[0][1]=tree[0][2]=0;
	for(i=0;i<=n;i++)
		son[i].clear();
	son[0].push_back(1);
	for(i=1; i<=n; i++) {
		tree[i][1]=1;
		while(cin>>x,x){
			tree[x][0]=i;
			son[i].push_back(x);
		}
	}
	level(0);
	while(q--) {
		scanf("%d%d",&x,&y);
		ans(x,y);
	}
}
