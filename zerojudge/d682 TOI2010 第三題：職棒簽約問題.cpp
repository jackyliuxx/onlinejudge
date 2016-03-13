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

int main () {
	int ans,m,i,j,k,n,p,a[60][60],b[60][60],f[10010],s0;
	while(cin>>m>>n>>p) {
		for(i=0; i<n; i++)
			for(j=0; j<p; j++)
				cin>>a[i][j]>>b[i][j];
		for(i=1; i<10010; i++)
			f[i]=-1;
		f[0]=0;
		for(i=0; i<n; i++) {
			for(j=m; j>=0; j--) {
				if(f[j]!=-1) {
					s0=0;
					for(k=0; k<p; k++) {
						if(j+a[i][k]<=m) {
							if(a[i][k]==0)
								s0=max(s0,b[i][k]);
							else
								f[j+a[i][k]]=max(f[j+a[i][k]],f[j]+b[i][k]);
						}
					}
					f[j]+=s0;
				}
			}
		}
		ans=0;
		for(i=0; i<=m; i++)
			ans=max(ans,f[i]);
		printf("%d\n",ans);
	}
}
