//by jackyliuxx
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
int n,a,b,c;

int f(int x){
	return a*x*x+b*x+c;
}

int gcd(int x,int y){
	if(!x) return y;
	return gcd(y%x,x);
}

int g[5140];

int gr(int x){
	return g[x]==x ? x : g[x]=gr(g[x]);
}

void lk(int x,int y){
	g[gr(y)]=gr(x);
}

int main () {
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&n,&a,&b,&c);
		int i,j,ans=n;
		for(i=0;i<n;i++)
			g[i]=i;
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				if(gcd(f(i),f(j))==1 && gr(i)!=gr(j)){
					ans--;
					lk(i,j);
				}
			}
		}
		printf("%d\n",ans);
	}
}

