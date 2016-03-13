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

int main () {
	int n;
	long long tx=1,ty=1,x,y;
	cin>>n;
	int i;
	for(i=0;i<n;i++){
		cin>>x>>y;
		tx*=x;
		ty*=y;
		if(x==0 && y!=0)
			ty=1;
	}
	if(tx<ty)
		puts("I'm Real Billy Denpa");
	else
		puts("My Orange Flower~");
}
