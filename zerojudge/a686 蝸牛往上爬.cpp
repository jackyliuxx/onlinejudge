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
	int n,a,b,c;
	scanf("%d",&n);
	while(n--) {
		scanf("%d%d%d",&a,&b,&c);
		if(b<=c)
			if(a>b)
				puts("Poor Snail");
			else
				puts("1");
		else
			printf("%d\n",(a-b)/(b-c)+(((a-b)%(b-c))>0)+1);
	}
}
