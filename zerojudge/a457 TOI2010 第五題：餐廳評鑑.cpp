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

int a[100010],b[100010],a2[100010],b2[100010];

long long ms(int b,int e,int *x,int *y,int *x2,int *y2) {
	long long i,j,k,r=0;
	if(e-b<=1)
		return 0;
	r+=ms(b,(b+e)/2,x,y,x2,y2);
	r+=ms((b+e)/2,e,x,y,x2,y2);
	for(i=k=b,j=(b+e)/2; i<(b+e)/2 && j<e; k++) {
		if(x[i]>x[j]) {
			x2[k]=x[j];
			y2[k]=y[j];
			r+=(b+e)/2-i;
			j++;
		}
		else if(x[i]==x[j] && y[i]>y[j]) {
			x2[k]=x[j];
			y2[k]=y[j];
			j++;
		}
		else {
			x2[k]=x[i];
			y2[k]=y[i];
			i++;
		}
	}
	while(i<(b+e)/2){
		x2[k]=x[i];
		y2[k]=y[i];
		i++;
		k++;
	}
	while(j<e){
		x2[k]=x[j];
		y2[k]=y[j];
		j++;
		k++;
	}
	for(i=b; i<e; i++) {
		x[i]=x2[i];
		y[i]=y2[i];
	}
	return r;
}


int main () {
	long long n,k,i,ans;
	while(cin>>n>>k) {
		for(i=0; i<n; i++)
			scanf("%d",&a[i]);
		for(i=0; i<n; i++)
			scanf("%d",&b[i]);
		ms(0,n,a,b,a2,b2);
		ans=ms(0,n,b,a,b2,a2);
		cout<<ans<<endl;
	}
}
