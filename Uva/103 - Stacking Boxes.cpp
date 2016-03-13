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
int k,n,ans[50][2];

struct box{
	int w[15],n;
}b[50];

bool operator <(box x,box y){
	int i;
	for(i=0;i<n;i++){
		if(x.w[i]<y.w[i])
			return true;
		if(x.w[i]>y.w[i])
			return false;
	}
	return false;
}

bool putin(box x,box y){
	int i;
	for(i=0;i<n;i++)
		if(x.w[i]>=y.w[i])
			return false;
	return true;
}

void ptans(int now){
	if(ans[now][1]==-1){
		printf("%d",b[now].n);
		return;
	}
	ptans(ans[now][1]);
	printf(" %d",b[now].n);
}


int main () {
	while(~scanf("%d%d",&k,&n)){
		int i,j;
		for(i=0;i<k;i++){
			b[i].n=i+1;
			for(j=0;j<n;j++)
				scanf("%d",b[i].w+j);
			sort(b[i].w,b[i].w+n);
		}
		sort(b,b+k);
		for(i=0;i<k;i++){
			ans[i][0]=1;
			ans[i][1]=-1;
			for(j=0;j<i;j++){
				if(putin(b[j],b[i]) && ans[j][0]+1>ans[i][0]){
					ans[i][0]=ans[j][0]+1;
					ans[i][1]=j;
				}
			}
		}
		int ma=0;
		for(i=0;i<k;i++){
			if(ans[i][0]>ma){
				ma=ans[i][0];
				j=i;
			}
		}
		printf("%d\n",ma);
		ptans(j);
		puts("");
	}
}
