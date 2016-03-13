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
bool hu[1010];
int b[1010],bp;

struct bead{
	int f,t,n;
	bead(int a,int b,int c){
		f=a;
		t=b;
		n=c;
	}
	bead(){}
	bool ihu(int p=0){
		if(p)
			hu[n]=true;
		return hu[n];
	}
};

vector<bead> a[51];


void gtku(int n){
	int i,hd=1;
	vector<bead> &x=a[n];
	for(i=0;i<x.size();i++){
		if(!x[i].ihu()){
			hd=0;
			x[i].ihu(1);
			gtku(x[i].t);
			b[bp++]=n;
		}
	}
	//if(hd)	b[bp++]=n;
	return;
}

void tku(){
	int i;
	for(i=1;i<51;i++)
		if(a[i].size())
			break;
	gtku(i);
}


int main () {
	int t,n,k=1;
	scanf("%d",&t);
	while(t--){
		bp=0;
		int i,x,y;
		for(i=0;i<51;i++)
			a[i].clear();
		scanf("%d",&n);
		for(i=0;i<n;i++)
			hu[i]=false;
		for(i=0;i<n;i++){
			scanf("%d%d",&x,&y);
			a[x].push_back(bead(x,y,i));
			a[y].push_back(bead(y,x,i));
		}
		if(k!=1)
			puts("");
		printf("Case #%d\n",k++);
		bool fs=false;
		for(i=1;i<51;i++)
			if(a[i].size()%2)
				fs=true;

		if(fs)
			puts("some beads may be lost");
		else{
			tku();
			b[bp++]=b[0];
			for(i=bp-1;i>0;i--)
				printf("%d %d\n",b[i],b[i-1]);
		}
	}
}

/*
7
1 2
2 4
4 3
3 1
2 3
3 2
4 4
*/
