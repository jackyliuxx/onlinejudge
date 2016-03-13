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

long long city[110000][2];
long long n;

bool check(long long x){
	long long i;
	long long cpt=0;
	for(i=0;i<n;i++){
		if(city[i][1]<x){
			cpt+=city[i][1]-x-city[i][0];
		}
		else
			cpt+=(city[i][1]-x-city[i][0] > 0 ? city[i][1]-x-city[i][0] : 0);
	}
	if(cpt>=0)
		return true;
	return false;
}

int main () {
	scanf("%lld",&n);
	long long i,r=0;
	for(i=0;i<n;i++){
		scanf("%d%d",city[i],city[i]+1);
		r=max(r,city[i][1]);
	}
	r++;
	long long l=-1,md;
	while(r-l>1){
		md=(l+r)/2;
		if(check(md))
			l=md;
		else
			r=md;
	}
	printf("%lld\n",l);
}
