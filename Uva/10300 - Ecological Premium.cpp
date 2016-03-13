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
	int n;
	cin>>n;
	while(n--) {
		long long k,a,b,c;
		cin>>k;
		long long ans=0;
		while(k--) {
			cin>>a>>b>>c;
			ans+=a*c;
		}
		cout<<ans<<endl;
	}
}
