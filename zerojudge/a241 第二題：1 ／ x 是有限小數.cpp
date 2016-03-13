#include<iostream>
using namespace std;
int main(){
	int i,m,n,ans,a2,a5;
	cin>>m;
	while(m--){
		ans=0;
		cin>>n;
		for(a5=1;a5<=n;a5*=5)
			for(a2=1;a2*a5<=n;a2*=2)
				ans++;
		ans--;
		cout<<ans<<endl;
	}
}