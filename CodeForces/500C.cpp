#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a[600];
	vector<int> v1,v2;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	int ans=0;
	while(m--){
		int x;
		scanf("%d",&x);
		x--;
		while(v1.size() && v1.back()!=x){
			ans+=a[v1.back()];
			v2.push_back(v1.back());
			v1.pop_back();
		}
		if(v1.size())
			v1.pop_back();
		while(v2.size()){
			v1.push_back(v2.back());
			v2.pop_back();
		}
		v1.push_back(x);
	}
	printf("%d\n",ans);
}
