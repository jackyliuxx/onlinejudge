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

int main () {
	int t,n;
	static int a[1001000];
	scanf("%d",&t);
	while(t--){
		long long fc=0,np=0;
		scanf("%d",&n);
		int i;
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		for(i=0;i<n;i++){
			np+=a[i];
			if(np<=0){
				fc+=1-np;
				np=1;
			}
		}
		long long mfc=fc;
		for(i=n-1;i>0;i--){
			if(a[i]<=0)
				fc+=1-a[i];
			else
				fc-=a[i];
			if(fc<0)
				fc=0;
			mfc=min(mfc,fc+n-i);
		}
		printf("%I64d\n",mfc);
	}
}
