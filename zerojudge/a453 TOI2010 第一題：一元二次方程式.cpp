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
	int n,i,a,b,c,ans;
	cin>>n;
	while(n--) {
		cin>>a>>b>>c;
		ans= (int) sqrt(double (b*b-4*a*c));
		if(ans>=0 && ans*ans==(b*b-4*a*c))
			puts("Yes");
		else
			puts("No");
	}
}
