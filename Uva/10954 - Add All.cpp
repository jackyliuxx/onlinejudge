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

priority_queue<int,vector<int>,greater<int> > pq;

int main () {
	int n;
	while(scanf("%d",&n),n){
		while(pq.size())
			pq.pop();
		int i,ans=0,x;
		for(i=0;i<n;i++){
			scanf("%d",&x);
			pq.push(x);
		}
		while(pq.size()>1){
			x=pq.top();
			pq.pop();
			x+=pq.top();
			pq.pop();
			ans+=x;
			pq.push(x);
		}
		printf("%d\n",ans);
	}
}
