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
	int n,a,b;
	double ans,ans2;
	cin>>n;
	while(n--){
		cin>>a>>b;
		ans=double (b-a)*10000/a;
		ans2=int (ans+(ans>=0 ? 0.5 : -0.5));
		printf("%6.2lf%% ",ans2/100);
		if( ans>=1000 || ans<=-700)
			puts("dispose");
		else
			puts("keep");
	}
}
