#include<bits/stdc++.h>
using namespace std;

int n,m,a[30001];
map<int,int> mp[30001];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<30001;i++){
		a[i]=0;
		mp[i].clear();
	}
	int mx=0;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		a[x]++;
		mx=max(mx,x);
	}
	mp[m][m]=a[m];
	int ans=0;
	map<int,int>::iterator it,itt;
	for(int i=1;i<=mx;i++){
		if(mp[i].empty())
			continue;
		for(it=mp[i].begin();it!=mp[i].end();it++){
			for(int j=-1;j<=1;j++){
				int nxt=i+it->first+j;
				if(nxt>mx)
					continue;
				int &tt=mp[nxt][nxt-i];
				if(tt < it->second+a[nxt])
					tt=it->second+a[nxt];
				ans=max(ans,tt);
			}
		}
	}
	printf("%d\n",ans);
}
