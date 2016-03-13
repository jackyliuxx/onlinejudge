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
#define ull unsigned long long
using namespace std;

struct zombie{
	ull code;
	int kind;
};

bool zbsort(zombie a,zombie b){
	return a.code<b.code;
}

ull q2(int n){
	ull r=1;
	while(n--)
		r*=2;
	return r;
}

int level(ull n){
	int i;
	for(i=0;n>0;i++)
		n/=2;
	return i;
}

int sfk(zombie *a,int i){
	ull n=a[i].code;
	int m;
	n/=2;
	while(n){
		int l=-1,u=i;
		while(u-l>1){
			m=(u+l)/2;
			if(a[m].code<n)
				l=m;
			else
				u=m;
		}
		if(a[u].code==n)
			return a[u].kind;
		n/=2;
	}
	return 0;
}

int main () {
	static zombie a[101000];
	int t,m,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&m,&n);
		ull totle=q2(m)-1;
		int i;
		for(i=0;i<n;i++)
			scanf("%I64u%d",&a[i].code,&a[i].kind);
		a[n].code=1,a[n].kind=1;
		n++;
		sort(a,a+n,zbsort);
		for(i=1;i<n;i++){
			if(sfk(a,i)!=a[i].kind){
				if(a[i].kind)
					totle+=q2(m-level(a[i].code)+1)-1;
				else
					totle-=q2(m-level(a[i].code)+1)-1;
			}
		}
		printf("%I64u\n",totle);
	}
}

