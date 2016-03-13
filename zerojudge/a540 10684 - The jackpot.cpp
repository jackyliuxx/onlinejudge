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
	int a,n,i,x,ans;
	while(cin>>n,n){
		ans=a=0;
		while(n--){
			cin>>x;
			a+=x;
			if(a<0)
				a=0;
			if(a>ans)
				ans=a;
		}
		if(ans)
			printf("The maximum winning streak is %d.\n",ans);
		else
			puts("Losing streak.");
	}
}
