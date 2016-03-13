#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

int hz(int a,int b){
	int t;
	while(a){
		t=b%a;
		b=a;
		a=t;
	}
	if(b==1)
		return 1;
	return 0;
}

int main () {
	int n,a[60];
	while(scanf("%d",&n),n){
		int i,j;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		int cnt=0;
		int all=0;
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++)
				cnt+=hz(a[i],a[j]),all++;
		if(cnt)
			printf("%.6lf\n",sqrt(6.0*all/cnt));
		else
			puts("No estimate for this data set.");
	}
}
