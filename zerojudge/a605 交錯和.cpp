#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <deque>
using namespace std;

#define MN (-2147483648)

struct ele{
	long long n;
	int o;
	ele(){}
	ele(long long _n,int _o):n(_n),o(_o){}
};

int main () {
	int n,m;
	static long long a[1100000];
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;i++)
			scanf("%lld",a+i);
		long long ans=a[0];
		deque<ele> q1,q2;
		q1.push_back(ele(a[0],0));
		for(int i=1;i<n;i++){
			while(q1.size() && q1.front().o<i-m)
				q1.pop_front();
			while(q2.size() && q2.front().o<i-m)
				q2.pop_front();
			long long nn1,nn2;
			if(q1.size()){
				nn1=q1.front().n-a[i];
			}
			
			if(q2.size()){
				nn2=max(q2.front().n+a[i],a[i]);
			}
			else
				nn2=a[i];
			
			while(q2.size() && q2.back().n<=nn1)
				q2.pop_back();
			while(q1.size() && q1.back().n<=nn2)
				q1.pop_back();
			q2.push_back(ele(nn1,i));
			q1.push_back(ele(nn2,i));

			if(q1.size())
				ans=max(ans,q1.front().n);
			if(q2.size())
				ans=max(ans,q2.front().n);
		}
		printf("%lld\n",ans);
	}
}
