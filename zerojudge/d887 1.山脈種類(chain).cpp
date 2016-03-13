#include<iostream>
using namespace std;
int main(){
	long long ans;
	int n,i;
	while(cin>>n){
		ans=1;
		for(i=1;i<=n;i++)
			ans*=n+i,ans/=i;
		ans/=n+1;
		cout<<ans<<endl;
	}
}