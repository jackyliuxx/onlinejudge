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
	static int a[1001000],ans[1001000];
	static int stk[1001000],stp;
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	stp=0;
	for(i=0;i<n;i++){
		while(stp && a[stk[stp-1]]<=a[i]){
			ans[stk[stp-1]]=i-stk[stp-1];
			stp--;
		}
		stk[stp++]=i;
	}
	for(i=0;i<stp;i++)
		ans[stk[i]]=n-stk[i]-1;
	for(i=0;i<n;i++)
		printf("%d\n",ans[i]);
}
