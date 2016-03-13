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
#include <map>
using namespace std;

struct treap{
	int v,sz,k,sum,mx,key;
	treap *l,*r;
	treap(){}
	treap(int _v,int _key):v(_v),k(rand()),sz(1),sum(_v),mx(_v),l(0),r(0),key(_key){}
};

int size(treap *t){
	return t ? t->sz : 0 ;
}

int mx(treap *t){
	return t ? t->mx : -99999999;
}

int sum(treap *t){
	return t ? t->sum : 0;
}

int pull(treap *t){
	t->sz=size(t->l)+size(t->r)+1;
	t->mx=max(t->v,max(mx(t->l),mx(t->r)));
	t->sum=sum(t->r)+sum(t->l)+t->v;
}

treap *merge(treap *a,treap *b){
	if(!a || !b)
		return a ? a : b;
	if( a->k > b->k){
		a->r = merge( a->r , b);
		pull(a);
		return a;
	}
	else{
		b->l = merge(a , b->l);
		pull(b);
		return b;
	}
}

void split(treap *t,int k,treap *&a,treap *&b){
	if(!t){
		a=b=0;
		return;
	}
	if(t->key <= k){
		a=t;
		split(t->r,k,a->r,b);
		pull(a);
	}
	else{
		b=t;
		split(t->l,k,a,b->l);
		pull(b);
	}
}

void kill(treap *t){
	if(!t)
		return;
	kill(t->l);
	kill(t->r);
	delete t;
}

int main () {
	int T;
	scanf("%d",&T);
	while(T--){
		int n,w;
		scanf("%d%d",&n,&w);
		int i,x,y,c;
		treap *t=0;
		for(i=0;i<n;i++){
			scanf("%d",&x);
			t=merge(t,new treap(x,i));
		}
		while(w--){
			scanf("%d",&c);
			treap *t1,*t2;
			if(c==3){
				scanf("%d",&x);
				split(t,x-1,t1,t);
				split(t,x,t,t2);
				printf("%d\n",t->v);
				t=merge(t1,t);
				t=merge(t,t2);
			}
			if(c==2){
				scanf("%d%d",&x,&y);
				split(t,x-1,t1,t);
				split(t,y,t,t2);
				printf("%d\n",sum(t)/size(t));
				t=merge(t1,t);
				t=merge(t,t2);
			}
			if(c==1){
				scanf("%d%d",&x,&y);
				split(t,x-1,t1,t);
				split(t,y,t,t2);
				printf("%d\n",mx(t));
				t=merge(t1,t);
				t=merge(t,t2);
			}
		}
		kill(t);
	}
}
