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

int haha(int *a,int now,int ns) {
	if(now==4) {
		if(ns==24)
			return 1;
		else
			return 0;
	}
	if(
	    haha(a,now+1,ns+a[now]) ||
	    haha(a,now+1,ns-a[now]) ||
	    (now!=0 && haha(a,now+1,ns*a[now])) ||
	    (now!=0 && ns%a[now]==0 && haha(a,now+1,ns/a[now]))
	)
		return 1;
	return 0;
}

int cal(int a,int b,int k) {
	switch(k) {
	case 1:
		return a+b;
		break;
	case 2:
		return a-b;
		break;
	case 3:
		return a*b;
		break;
	case 4:
		if(b!=0 && a%b==0)
			return a/b;
		break;
	}
	return 99;
}


int huhu(int *a) {
	for(int i=1; i<=4; i++)
		for(int j=1; j<=4; j++)
			for(int k=1; k<=4; k++)
				if(cal(cal(a[0],a[1],j),cal(a[2],a[3],k),i)==24)
					return 1;
	return 0;
}



int main () {
	int a[4];
	while(scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]),a[0]) {
		int YON=0;
		sort(a,a+4);
		do {
			YON+=haha(a,0,0);
			YON+=huhu(a);
		} while(YON==0 && next_permutation(a,a+4));
		if(YON)
			puts("YES");
		else
			puts("NO");
	}
}
