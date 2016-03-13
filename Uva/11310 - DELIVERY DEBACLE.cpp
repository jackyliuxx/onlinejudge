#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int main () {
	long long a[41]={0,1,5,11},n,i,m;
	cin>>m;
	while(m--){
		cin>>n;
		for(i=4;i<=n;i++)
			a[i]=a[i-1]*1+a[i-2]*4+a[i-3]*2;
		cout<<a[n]<<endl;
	}
}
