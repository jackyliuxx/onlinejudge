//by jackyliuxx
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int main () {
	int t;
	char s[5140];
	scanf("%d",&t);
	gets(s);
	while(t--){
		gets(s);
		int ans=0;
		for(int i=0;s[i];i++){
			if(s[i]=='H')
				ans++;
			if(s[i]=='X')
				ans+=2;
		}
		printf("%d\n",ans);
	}
}
