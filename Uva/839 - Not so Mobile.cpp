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

int godo(bool &yn){
	int aw,ad,bw,bd;
	scanf("%d%d%d%d",&aw,&ad,&bw,&bd);
	if(aw==0)
		aw=godo(yn);
	if(bw==0)
		bw=godo(yn);
	if(aw*ad!=bw*bd)
		yn=false;
	return aw+bw;
}

int main () {
	int t,k=0;
	scanf("%d",&t);
	while(t--){
		bool yn=true;
		godo(yn);
		if(k++)
			puts("");
		if(yn)
			puts("YES");
		else
			puts("NO");
	}
}
