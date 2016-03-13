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
	int t,n,m;
	cin>>t;
	while(t--) {
		cin>>n>>m;
		int a[110][110]= {};
		int w,wp,x,y,i,j;
		wp=1-m/2*2;
		w=m;
		x=y=0;
		for(i=1; i<=n*n; i++) {
			a[y][x]=i;
			if( x+(w==1)-(w==3) >= n || y+(w==2)-(w==0) >=n ||
			        x+(w==1)-(w==3) < 0 || y+(w==2)-(w==0) <0 ||
			        a[y+(w==2)-(w==0)][x+(w==1)-(w==3)]!=0){
				w+=wp;
				w=(w+4)%4;
			        }
			x+=(w==1)-(w==3);
			y+=(w==2)-(w==0);
		}
		for(i=0; i<n; i++) {
			for(j=0; j<n; j++)
				printf("%5d",a[i][j]);
			puts("");
		}
		puts("");
	}
}
