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

struct haha {
	int t;
	vector<int> v;
}a[1010];

int ser(int now){
	int ul=0,i;
	if(a[now].v.size()){
		for(i=0;i<a[now].v.size();i++)
			ul=max(ser(a[now].v[i]),ul);
		a[now].v.clear();
		a[now].t+=ul;
	}
	return a[now].t;
}

int main () {
	int t,n,k,i,j,l,ans;
	cin>>t;
	while(t--) {
		for(i=0; i<1010; i++)
			a[i].v.clear();
		cin>>n;
		for(i=1; i<=n; i++) {
			cin>>l;
			a[i].t=l;
			cin>>k;
			for(j=0; j<k; j++) {
				cin>>l;
				a[l].v.push_back(i);
			}
		}
		ans=0;
		for(i=1;i<=n;i++)
			ans=max(ans,ser(i));
		cout<<ans<<endl;
	}
}
