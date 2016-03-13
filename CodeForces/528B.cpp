#include<bits/stdc++.h>
using namespace std;

struct vt{
	int p,w;
	bool operator<(vt b)const{
		return p+w<b.p+b.w;
	}
};

int main(){
	int n;
	scanf("%d",&n);
	static vt v[210000];
	for(int i=0;i<n;i++){
		scanf("%d%d",&v[i].p,&v[i].w);
	}
	sort(v,v+n);
	map<int, int> mp;
	mp[v[0].p+v[0].w] = 1;
	int ans=1;
	for(int i=1;i<n;i++){
		auto t = mp.upper_bound(v[i].p-v[i].w);
		int x=0;
		if(t!=mp.begin()){
			t--;
			x=t->second;
		}
		/*
		int y=0;
		t= mp.lower_bound(v[i].p+v[i].w);
		if(t!=mp.end())
			y=t->second;
		*/
		mp[v[i].p+v[i].w] = ans = max(ans,x+1);
	}
	printf("%d\n",ans);
}
