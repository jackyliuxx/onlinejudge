#include<bits/stdc++.h>
using namespace std;

struct treap{
	int v,sm,lsm,rsm,mdsm,cgn,sz,pri;
	bool rv,cg;
	treap *l,*r;
	treap(int _v):v(_v),sm(_v),lsm(_v),rsm(_v),mdsm(_v),sz(1),pri((rand()<<16)+rand()),rv(false),cg(false),l(NULL),r(NULL){}
};
void push(treap *t){
	if(!t) return;
	if(t->rv){
		swap(t->l,t->r);
		swap(t->lsm,t->rsm);
		if(t->l)
			t->l->rv ^= 1;
		if(t->r)
			t->r->rv ^= 1;
		t->rv=false;
	}
	if(t->cg){
		t->v=t->cgn;
		t->sm=t->sz*t->v;
		if(t->sm>0)
			t->lsm=t->rsm=t->mdsm=t->sm;
		else
			t->lsm=t->rsm=t->mdsm=t->v;
		if(t->l)
			t->l->cg=true,t->l->cgn=t->cgn;
		if(t->r)
			t->r->cg=true,t->r->cgn=t->cgn;
		t->cg=false;
	}
}

int size(treap *t){return t?t->sz:0;}
int lsum(treap *t){return t?t->lsm:-999999999;}
int rsum(treap *t){return t?t->rsm:-999999999;}
int sum(treap *t){return t?t->sm:0;}
int mdsum(treap *t){return t?t->mdsm:-999999999;}
void pull(treap *t){
	push(t->l);
	push(t->r);
	t->sz=size(t->l)+size(t->r)+1;
	t->sm=sum(t->l)+sum(t->r)+t->v;
	t->lsm=max(lsum(t->l),sum(t->l)+max(lsum(t->r),0)+t->v);
	t->rsm=max(rsum(t->r),sum(t->r)+max(rsum(t->l),0)+t->v);
	t->mdsm=max(max(mdsum(t->l),mdsum(t->r)),max(rsum(t->l),0)+max(lsum(t->r),0)+t->v);
}

treap *merge(treap *a,treap *b){
	push(a);
	push(b);
	if(!a||!b) return a?a:b;
	if(a->pri > b->pri){
		a->r=merge(a->r,b);
		pull(a);
		return a;
	}
	else{
		b->l=merge(a,b->l);
		pull(b);
		return b;
	}
}

void split(treap *t,int k,treap *&a,treap *&b){
	if(!t){
		a=b=NULL;
		return;
	}
	push(t);
	if(size(t->l)>=k){
		b=t;
		split(t->l,k,a,b->l);
		pull(b);
	}
	else{
		a=t;
		split(t->r,k-size(t->l)-1,a->r,b);
		pull(a);
	}
}

void kill(treap *t){
	if(!t)
		return;
	kill(t->l);
	kill(t->r);
	delete t;
}

void print(treap *t){
	if(!t)
		return;
	print(t->l);
	printf("v=%d sm=%d lsm=%d rsm=%d mdsm=%d sz=%d\n",t->v,t->sm,t->lsm,t->rsm,t->mdsm,t->sz);
	print(t->r);
}

void insert(treap *&t){
	int p,k;
	scanf("%d%d",&p,&k);
	treap *a,*b;
	split(t,p,a,b);
	while(k--){
		int x;
		scanf("%d",&x);
		a=merge(a,new treap(x));
	}
	t=merge(a,b);
}

void del(treap *&t){
	int p,k;
	scanf("%d%d",&p,&k);
	treap *a,*b,*c,*d;
	split(t,p-1,a,b);
	split(b,k,c,d);
	kill(c);
	t=merge(a,d);
}

void mksame(treap *&t){
	int p,k,l;
	scanf("%d%d%d",&p,&k,&l);
	treap *a,*b,*c,*d;
	split(t,p-1,a,b);
	split(b,k,c,d);
	c->cg=true;
	c->cgn=l;
	b=merge(c,d);
	t=merge(a,b);
}

void rev(treap *&t){
	int p,k;
	scanf("%d%d",&p,&k);
	treap *a,*b,*c,*d;
	split(t,p-1,a,b);
	split(b,k,c,d);
	c->rv^=true;
	b=merge(c,d);
	t=merge(a,b);
}

void getsum(treap *&t){
	int p,k;
	scanf("%d%d",&p,&k);
	treap *a,*b,*c,*d;
	split(t,p-1,a,b);
	split(b,k,c,d);
	printf("%d\n",sum(c));
	b=merge(c,d);
	t=merge(a,b);
}

void maxsum(treap *&t){
	push(t);
	printf("%d\n",mdsum(t));
}

int main(){
	srand(time(NULL));
	int n,m;
	scanf("%d%d",&n,&m);
	treap *t=NULL;
	while(n--){
		int x;
		scanf("%d",&x);
		t=merge(t,new treap(x));
	}
	while(m--){
		push(t);
		char s[20];
		scanf("%s",s);
		if(!strcmp(s,"INSERT"))
			insert(t);
		if(!strcmp(s,"DELETE"))
			del(t);
		if(!strcmp(s,"MAKE-SAME"))
			mksame(t);
		if(!strcmp(s,"REVERSE"))
			rev(t);
		if(!strcmp(s,"GET-SUM"))
			getsum(t);
		if(!strcmp(s,"MAX-SUM"))
			maxsum(t);
		//print(t);
	}
}
