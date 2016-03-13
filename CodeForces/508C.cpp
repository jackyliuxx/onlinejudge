#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,t,r,gt[310];
	scanf("%d%d%d",&n,&t,&r);
	for(int i=0;i<n;i++)
		scanf("%d",gt+i);
	if(t<r){
		puts("-1");
		return 0;
	}
	bool hs[1000]={};
	queue<int> q;
	int cds=0;
	sort(gt,gt+n);
	int ncs=gt[n-1];
	int ans=0;
	for(int i=n-1;i>=0;i--){
		while(!q.empty() && q.front()>gt[i]){
			q.pop();
			cds--;
		}
		ncs=gt[i]-t+1;
		while(cds<r){
			while(hs[ncs+500])ncs++;
			int k=ncs;
			hs[k+500]=true;
			q.push(k);
			cds++;
			ans++;
		}
	}
	printf("%d\n",ans);
}
