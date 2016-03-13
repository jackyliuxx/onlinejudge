#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int main(){
	long long t,n,m,i,ans,j,b2;
	vector<long long> a,b;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		ans=0;
		a.clear();
		b.clear();
		for(i=0;i<n;i++){
			scanf("%lld",&m);
			if(a.empty()){
				a.push_back(m);
				b.push_back(1);
			}
			else{
				b2=1;
				for(j=a.size()-1;j>=0 && a[j]<=m;j--){
					if(a[j]<m){
						ans+=b.back();
						a.pop_back();
						b.pop_back();
					}
					else{
						ans+=b.back();
						b2+=b.back();
						a.pop_back();
						b.pop_back();
					}
				}
				if(j>=0)
					ans++;
				a.push_back(m);
				b.push_back(b2);
			}
		}
		printf("%lld\n",ans);
	}
}