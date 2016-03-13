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

priority_queue<LL> l;
priority_queue< LL,vector<LL>,greater<LL> > r;

int main () {
	int n;
	LL cdst=0,dst=0;
	scanf("%d",&n);
	while(n--) {
		LL x,y;
		scanf("%I64d%I64d",&x,&y);
		if(x>y)
			swap(x,y);
		if(l.empty()) {
			dst=y-x;
			cdst=y-x;
			l.push(x);
			r.push(y);
		}
		else {
			cdst+=y-x;
			dst+=abs(x-l.top())+abs(y-l.top());
			if(x<l.top())
				l.push(x);
			else
				r.push(x);
			if(y<l.top())
				l.push(y);
			else
				r.push(y);
			if(l.size()<r.size()){
				dst+=(r.top()-l.top())*((LL)l.size()-r.size());
				l.push(r.top());
				r.pop();
			}
			if(l.size()>r.size()){
				LL nx=l.top();
				l.pop();
				dst+=(nx-l.top())*((LL)r.size()+1-l.size());
				r.push(nx);
			}
		}
		printf("%I64d\n",(dst-cdst)/2);
	}
}
