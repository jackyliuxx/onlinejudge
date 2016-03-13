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
using namespace std;

int main () {
	int n,a[30],k;
	char s[30],s2[30];
	while(scanf("%d",&n)!=EOF) {
		int i,j;
		for(i=0; i<n; i++)
			scanf("%d",a+i);
		scanf("%s",s);
		scanf("%d",&k);
		for(i=0; i<k; i++) {
			for(j=0; j<n; j++)
				s2[j]=s[a[j]-1];
			s2[n]=0;
			strcpy(s,s2);
		}
		puts(s);
	}
}
