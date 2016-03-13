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
#define MN -2100000000
#define MD 100000
int dp[210000];

void dpush(int x,int y){
	int st,ed,w;
	if(x<0){
		st=0-x;
		ed=200001;
		w=1;
	}
	else{
		st=200000-x;
		ed=-1;
		w=-1;
	}
	int i;
	for(i=st;i!=ed;i+=w){
		if(dp[i]!=MN){
			dp[i+x]=max(dp[i+x],dp[i]+y);
		}
	}
}

int dmax(){
	int i,mx=MN;
	for(i=MD;i<=200000;i++)
		if(dp[i]>=0)
			mx=max(mx,i-MD+dp[i]);
	return mx;
}



int main () {
	int n;
	scanf("%d",&n);
	int i,x,y;
	for(i=0;i<210000;i++)
		dp[i]=MN;
	dp[MD]=0;
	for(i=0;i<n;i++){
		scanf("%d%d",&x,&y);
		dpush(x,y);
	}
	printf("%d\n",dmax());
}
