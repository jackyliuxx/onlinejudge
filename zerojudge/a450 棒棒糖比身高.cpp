#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

struct qq{
	int n,i,s;
};

bool qst(qq a,qq b){
	return a.n<b.n;
}

int readint(int &n){
	char c;
	while(c=getchar(),c!='-' && (c<'0' || c>'9'));
	int k=1;
	n=0;
	if(c=='-')
		k=-1;
	else
		n=c-'0';
	while(c=getchar(),c>='0' && c<='9') n=n*10+c-'0';
	n*=k;
	return n;
}

int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	static int *candies=new int[n];
	static qq *qa=new qq[q],*qb=new qq[q];
	int i;
	for(i=0;i<n;i++)
		readint(candies[i]);
	for(i=0;i<q;i++){
		readint(qa[i].n);
		readint(qb[i].n);
		qa[i].i=qb[i].i=i;
	}
	sort(candies,candies+n);
	sort(qa,qa+q,qst);
	sort(qb,qb+q,qst);
	int cp,ct;
	for(ct=0,cp=n-1,i=q-1;i>=0;i--){
		while(cp>=0 && candies[cp]>=qa[i].n)
			cp--,ct++;
		qa[i].s=ct;
	}
	for(ct=0,cp=n-1,i=q-1;i>=0;i--){
		while(cp>=0 && candies[cp]>qb[i].n)
			cp--,ct++;
		qb[i].s=ct;
	}
	static int *ans=new int[q];
	for(i=0;i<q;i++)
		ans[qa[i].i]=qa[i].s;
	for(i=0;i<q;i++)
		ans[qb[i].i]-=qb[i].s;
	for(i=0;i<q;i++){
		if(ans[i]>0)
			printf("%d\n",ans[i]);
		else
			puts("The candies are too short");
	}
}

