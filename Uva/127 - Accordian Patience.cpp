#include <cstdio>     //waaaaaa
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

struct card {
	char a,b;
	card() {}
	card(char x,char y) {
		a=x,b=y;
	}
};

list<card> crd[52];
int llst[60],lst[60],nlst[60],litz;

int nlst3(int n){
	int i;
	int r=n;
	for(i=0;r!=-1 && i<3;i++)
		r=nlst[r];
	return r;
}

int llst3(int n){
	int i;
	int r=n;
	for(i=0;r!=-1 && i<3;i++)
		r=llst[r];
	return r;
}

void rmv(int n){
	nlst[llst[n]]=nlst[n];
	llst[nlst[n]]=llst[n];
	litz--;
}
/*
bool mcd(int x,int y){
	if(crd[x].back().a==crd[y].back().a || crd[x].back().b==crd[y].back().b){
		list<card>::iterator i;
		for(i=crd[y].begin();i!=crd[y].end();i++)
			crd[x].push_back(*i);
		rmv(y);
		return true;
	}
	return false;
}
*/
bool mcd(int x,int y){
	if(crd[x].back().a==crd[y].back().a || crd[x].back().b==crd[y].back().b){
		crd[x].push_back(crd[y].back());
		crd[y].pop_back();
		if(crd[y].empty())
			rmv(y);
		return true;
	}
	return false;
}

int main () {
	int i;
	char s[10];
	while(1) {
		for(i=0; i<52; i++) {
			scanf("%s",s);
			if(strcmp(s,"#")==0)
				return 0;
			crd[i].clear();
			crd[i].push_back(card(s[0],s[1]));
		}
		for(i=0;i<52;i++)
			lst[i]=i,nlst[i]=i+1,llst[i]=i-1;
		nlst[51]=-1;
		litz=52;
		i=0;
		while(i!=-1){
			int x,y;
			x=i;
			y=llst3(x);
			if(y!=-1 && mcd(y,x)){
				i=0;
				continue;
			}
			y=llst[x];
			if(y!=-1 && mcd(y,x)){
				i=0;
				continue;
			}
			i=nlst[i];
		}
		if(litz==1)
			printf("%d pile remaining:",litz);
		else
			printf("%d piles remaining:",litz);
		for(i=0;i!=-1;i=nlst[i])
			printf(" %d",crd[i].size());
		puts("");
	}
}
