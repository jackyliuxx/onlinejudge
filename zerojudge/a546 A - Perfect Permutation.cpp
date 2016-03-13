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
	while(cin>>n){
		if(n%2)
			puts("-1");
		else{
			for(int i=1;i<=n;i+=2)
				printf("%d %d ",i+1,i);
			puts("");
		}
	}
}
