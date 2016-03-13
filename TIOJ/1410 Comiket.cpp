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
	int n;
	static int a[1001000],b[1001000];
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++)
		scanf("%d%d",a+i,b+i);
	sort(a,a+i);
	sort(b,b+i);
	int mx=0,now=0;
	for(i=0,j=0;i<n || j<n;){
		if((i<n && j<n && a[i]<=b[j]) || j>=n)
			now++,i++;
		else
			now--,j++;
		mx=max(mx,now);
	}
	printf("%d\n",mx);
}
