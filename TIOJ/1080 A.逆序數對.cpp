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

long long haha(int *a,int *b,int first,int end){
	int i,j,half=(first+end)/2;
	if(end-first<2)
		return 0;
	long long rt=haha(a,b,first,half)+haha(a,b,half,end);
	int p=first;
	for(i=first,j=half;i<half || j<end;){
		if((i<half && j<end && a[i]<=a[j]) || j>=end){
			b[p++]=a[i];
			i++;
		}
		else{
			b[p++]=a[j];
			j++;
			rt+=half-i;
		}
	}
	for(i=first;i<end;i++)
		a[i]=b[i];
	return rt;
}


int main () {
	int n,cs=1;
	int a[101000],b[101000];
	while(scanf("%d",&n),n) {
		int i;
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		printf("Case #%d: %I64d\n",cs++,haha(a,b,0,n));
	}
}

