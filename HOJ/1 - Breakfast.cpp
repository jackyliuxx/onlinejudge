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
#include <list>
#include <map>
using namespace std;

int dp[5140];

int main () {
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	int i;
	for(i=3;i<5140;i++)
		if(~dp[i-3])
			dp[i]=(~dp[i] ? min(dp[i],dp[i-3]+1) : dp[i-3]+1);
	for(i=5;i<5140;i++)
		if(~dp[i-5])
			dp[i]=(~dp[i] ? min(dp[i],dp[i-5]+1) : dp[i-5]+1);
	int n;
	while(~scanf("%d",&n)){
		if(~dp[n])
			printf("%d\n",dp[n]);
		else
			puts("This is Kongming's Trap!!!");
	}
}
