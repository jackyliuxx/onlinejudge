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
using namespace std;

bool rv(int a,int b) {
	return a>b;
}

int main () {
	int n,a[10];
	while(~scanf("%d",&n)) {
		int i;
		for(i=0; i<n; i++)
			scanf("%d",a+i);
		sort(a,a+n,rv);
		int x=0,y=0;
		for(i=0; i<n; i++) {
			if(x>y)
				y=y*10+a[i];
			else
				x=x*10+a[i];
		}
		printf("%d\n",x*y);
	}
}
