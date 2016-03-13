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

int ct[20][70000];

int gohit(int n,int a[],int np,int dead) {
	if(ct[np][dead])
		return ct[np][dead];
	if(dead==(1<<n)-1)
		return ct[np][dead]=(np+a[np])/a[np]*a[np];
	int i;
	ct[np][dead]=2147483647;
	for(i=0; i<n; i++)
		if((dead&(1<<i))==0)
			ct[np][dead]=min(ct[np][dead],(gohit(n,a,i,dead|(1<<i))+abs(np-i)+a[np]-1)/a[np]*a[np]);
	return ct[np][dead];
}

int main () {
	int n,a[20];
	scanf("%d",&n);
	int i;
	for(i=0; i<n; i++)
		scanf("%d",a+i);
	int ans=2147483647;
	for(i=0; i<n; i++)
		ans=min(ans,gohit(n,a,i,1<<i));
	printf("%d",ans);
}
