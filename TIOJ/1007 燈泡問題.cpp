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
	long long n,m,a[100][20];
	while(cin>>n>>m){
		int i,j;
		for(i=0;i<=n;i++)
			a[0][i]=0;
		a[0][0]=1;
		for(i=1;i<=m;i++){
			a[i][0]=0;
			for(j=0;j<=n;j++)
				a[i][0]+=a[i-1][j];
			for(j=1;j<=n;j++)
				a[i][j]=a[i-1][j-1];
		}
		long long ans=0;
		for(i=0;i<=n;i++)
			ans+=a[m][i];
		cout<<ans<<endl;
	}
}
