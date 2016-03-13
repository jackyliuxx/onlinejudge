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
	int w,l;
	int i,j;
	static int a[220][220];
	for(i=0; i<220; i++)
		a[i][0]=a[0][i]=0;
	while(scanf("%d%d",&w,&l)!=EOF && w && l) {
		for(i=1; i<=w; i++) {
			for(j=1; j<=l; j++) {
				scanf("%d",&a[i][j]);
				a[i][j]=(a[i][j] ? 0 : 1);
				if(a[i][j])
					a[i][j]=a[i-1][j]+1;
			}
		}
		int ans=0;
		for(i=1; i<=w; i++) {
			int stkh[220],stki[220],sp=1;
			stkh[0]=stki[0]=0;
			for(j=1; j<=l; j++) {
				while(sp && stkh[sp-1]>=a[i][j]) {
					if(stkh[sp-1])
						ans=max(ans,stkh[sp-1]*(j-1-stki[sp-2]));
					sp--;
				}
				stkh[sp]=a[i][j];
				stki[sp]=j;
				sp++;
			}
			while(sp>1) {
				ans=max(ans,stkh[sp-1]*(l-stki[sp-2]));
				sp--;
			}
		}
		printf("%d\n",ans);
	}
}
