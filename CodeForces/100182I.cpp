#include<bits/stdc++.h>
using namespace std;
#define M 1000000
int dp[12][1024][2048];
int nn,mm;

int mkdp(int n,int m,int x){
	if(~dp[n][m][x])
		return dp[n][m][x];
	dp[n][m][x]=0;
	if(n>1){
		int kx=(x>>(n-2))%4;
		if(kx==3)
			for(int i=1;i<4;i++){
				dp[n][m][x]+=mkdp(n-2,m,x^(i<<(n-2)));
				dp[n][m][x]%=M;
			}
		if(kx==2 || kx==1)
			dp[n][m][x]+=mkdp(n-2,m,x&(~(3<<(n-2))));
	}
	else if(n==1){
		if(x%4==3 || x%4==0)
			dp[n][m][x]=mkdp(nn,m-1,(x>>2)<<2);
		else if(x%4==2)
			dp[n][m][x]=mkdp(nn,m-1,x|3);
	}
	else if(n==0){
		dp[n][m][x]=mkdp(nn,m-1,x);
	}
	dp[n][m][x]%=m;
	return dp[n][m][x];
}

int main(){
	while(cin>>nn>>mm,nn||mm){
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<=nn;i++){
			dp[i][1][((1<<nn)-1)^((1<<i)-1)]=1;
			for(int j=0;j<(1<<nn);j++)
				if(dp[i][1][j]==-1)
					dp[i][1][j]=0;
		}

		printf("%d\n",mkdp(nn,mm,(1<<(nn+2))-1));
	}
}

