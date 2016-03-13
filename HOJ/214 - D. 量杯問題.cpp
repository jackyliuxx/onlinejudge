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

int a[110];

int main () {
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int i,mm=514514514;
		for(i=0;i<n;i++){
			scanf("%d",a+i);
			mm=min(mm,a[i]);
		}
		int ans=0;
		for(i=0;i<n;i++)
			ans+=a[i]-mm;
		printf("%d\n",ans);
	}
}
