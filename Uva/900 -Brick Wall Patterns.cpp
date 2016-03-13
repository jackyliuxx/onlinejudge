#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int main () {
	long long a[51]={0,1,2},n,i;
	while(cin>>n,n){
		for(i=3;i<=n;i++)
			a[i]=a[i-1]+a[i-2];
		cout<<a[n]<<endl;
	}
}