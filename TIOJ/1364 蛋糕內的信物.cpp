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

int main () {
	int n,k;
	static int b[1001000];
	while(scanf("%d%d",&n,&k)!=EOF){
		int i,x;
		for(i=0;i<1001000;i++)
			b[i]=0;
		for(i=0;i<n;i++)
			scanf("%d",&x),b[x]++;
		int ct=0;
		for(i=0;i<1001000 && ct<=n-k;i++){
			if(b[i]){
				b[i]--;
				ct++;
				i--;
			}
		}
		printf("%d\n",i);
	}
}
