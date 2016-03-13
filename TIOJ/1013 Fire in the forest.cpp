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
using namespace std;

int rpx[4]= {-1,0,1,0},rpy[4]= {0,1,0,-1};
queue<int> fqx,fqy,nqx,nqy,fqt,nqt;

void blabla(char map[][18],int x,int y,int st) {
	int i;
	map[x][y]='F';
	for(i=0; i<4; i++) {
		if(map[x+rpx[i]][y+rpy[i]]=='.')
			fqx.push(x+rpx[i]),fqy.push(y+rpy[i]),fqt.push(st+1);
	}
}

void burn(char map[][18],int nt) {
	while(fqt.size() && fqt.front()<nt) {
		blabla(map,fqx.front(),fqy.front(),fqt.front());
		fqx.pop(),fqy.pop(),fqt.pop();
	}
}

bool runrun(char map[][18],int x,int y,int st) {
	if(map[x][y]=='E')
		return true;
	if(map[x][y]=='F')
		return false;
	int i;
	for(i=0; i<4; i++) {
		if(map[x+rpx[i]][y+rpy[i]]=='.' || map[x+rpx[i]][y+rpy[i]]=='E')
			nqx.push(x+rpx[i]),nqy.push(y+rpy[i]),nqt.push(st+1);
	}
	return false;
}

bool gorun(char map[][18],int nt) {
	while(nqt.size() && nqt.front()<nt) {
		if(runrun(map,nqx.front(),nqy.front(),nqt.front()))
			return true;
		nqx.pop(),nqy.pop(),nqt.pop();
	}
	return false;
}

int ckck(char map[][18],int nt) {
	int st;
	for(st=1; nqt.size(); st++) {
		if(gorun(map,st))
			return st;
		burn(map,nt+st);
	}
	return -1;
}

int main () {
	int fx,fy,nt,npx,npy,spx,spy;
	char map[10][18]= {"*****************",
	                   "*...*.......**..*",
	                   "**..*....*.*.*..*",
	                   "*......*.**.**.**",
	                   "*..**...**..**.**",
	                   "**.....**..*.*..*",
	                   "*....*..........*",
	                   "*.....****.*...**",
	                   "****.*.*........*",
	                   "*****************"
	                  };
	scanf("%d%d",&fx,&fy);
	scanf("%d",&nt);
	scanf("%d%d%d%d",&npx,&npy,&spx,&spy);
	while(fqx.size())
		fqx.pop();
	while(fqy.size())
		fqy.pop();
	while(nqx.size())
		nqx.pop();
	while(nqy.size())
		nqy.pop();
	while(fqt.size())
		fqt.pop();
	while(nqt.size())
		nqt.pop();
	fqx.push(fx),fqy.push(fy),fqt.push(0);
	map[spx][spy]='E';
	int i;
	burn(map,nt);
	nqx.push(npx),nqy.push(npy),nqt.push(0);
	int ans;
	ans=ckck(map,nt);
	if(ans!=-1)
		printf("%d\n",ans-1);
	else
		puts("Help!");
}



