#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,k;
	int rp[1100];
	while(cin>>n>>m>>k,n||m||k){
	for(int i=0;i<k;i++)
		cin>>rp[i];
	int ans=n;
	for(int i=0;i<m-1;i++){
		n+=rp[i%k];
		ans+=n;
	}
	cout<<ans<<endl;
	}
}
