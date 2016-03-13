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
	int n,ans[60]={1};
	for(int i=1;i<=50;i++)
		ans[i]=ans[i-1]+i;
	while(cin>>n)
		cout<<ans[n]<<endl;
}
