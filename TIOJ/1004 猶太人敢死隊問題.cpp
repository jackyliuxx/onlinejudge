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

int ans(int n) {
	if(n==1)
		return 0;
	return (ans(n-1)+2)%n;
}
int main () {
	int n;
	while(cin>>n)
		cout<<ans(n)+1<<endl;
}
