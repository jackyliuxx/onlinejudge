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

long long gcd(long long a,long long b){
	return a ? gcd(b%a,a) : b;
}

struct item{
	long long c,p;
	double cp;
	item(long long _c,long long _p){
		c=_c;
		p=_p;
		if(p==0)
			cp=99999999;
		else
			cp=double(c)/p;
	}
	item(){}
	bool operator <(const item x)const{
		return cp>x.cp;
	}
};

int main () {
	long long t,n;
	static item a[2000000];
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		long long x,y;
		for(long long i=0;i<n;i++){
			scanf("%lld%lld",&x,&y);
			a[i]=item(y,x);
		}
		sort(a,a+n);
		long long nc=1,c=0,p=1;
		for(long long i=0;i<n;i++){
			c+=nc*a[i].p;
			p+=a[i].p;
			nc+=a[i].c;
		}
		long long g=gcd(c,p);
		printf("%lld %lld\n",c/g,p/g);
	}
}
