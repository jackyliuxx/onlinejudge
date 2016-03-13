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
#define LL long long
LL wtf[1100000];

struct treap{
	int pri,v,size;
	treap *l,*r;
	treap(){}
	treap(int _v):v(_v),pri(rand()),size(1),l(0),r(0){}
};

int size(treap *t){
	return t ? t->size : 0;
}

void pull(treap *t){
	t->size=size(t->l)+size(t->r)+1;
}

treap *merge(treap *x,treap *y){
	if(!x || !y) return x ? x : y;
	if(x->pri < y->pri){
		y->l=merge(x,y->l);
		pull(y);
		return y;
	}
	else{
		x->r=merge(x->r,y);
		pull(x);
		return x;
	}
}

void split(treap *t,int k,treap *&a,treap *&b){
	if(!t){
		a=b=0;
		return;
	}
	if( size(t->l) < k ){
		a=t;
		split(t->r,k-size(t->l)-1,a->r,b);
		pull(a);
	}
	else{
		b=t;
		split(t->l,k,a,b->l);
		pull(b);
	}
}


int getn(treap *&t,int k){
	treap *tl,*tr;
	int r;
	split(t,k-1,tl,t);
	split(t,1,t,tr);
	r=t->v;
	delete t;
	t=merge(tl,tr);
	return r;
}

struct prg{
	LL n,od;
	prg(LL _n,LL _od){
		n=_n;
		od=_od;
	}
	prg(){};
};

list<prg> lst;
list<prg>::iterator it,it2;

int main () {
	srand(514);
	int hmt;
	scanf("%d",&hmt);
	while(hmt--){
		LL n,m,x,a,b,i;
		scanf("%lld%lld%lld%lld%lld",&n,&m,&x,&a,&b);
		wtf[0]=x;
		for(i=1;i<=n;i++){
			wtf[i]=(a*wtf[i-1]+b)%m;
		}
		for(i=1;i<=n;i++){
			wtf[i]=(wtf[i]+n-i)%(n-i+1)+1;
		}
		treap *t=0;
		for(i=1;i<=n;i++){
			t=merge(t,new treap(i));
		}
		lst.clear();
		for(i=1;i<=n;i++){
			lst.push_back(prg(getn(t,wtf[i]),i));
		}
		LL ans=0;
		i=1;
		while(lst.size()>1){
			for(it=lst.begin(),it2=it,it2++ ; it2!=lst.end() ;it2++){
				if( it->n < it2->n ){
					ans+=(it->od)*i++;
					it=lst.erase(it);
				}
				else
					it++;
			}
		}
		ans+=(lst.begin()->od)*i;
		printf("%lld\n",ans);
	}
}
