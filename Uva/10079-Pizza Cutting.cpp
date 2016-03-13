#include<iostream>
using namespace std;
int main(){
	long long n,ans;
	while(cin>>n,n>=0){
		ans=1;
		for(int i=1;i<=n;i++)
			ans+=i;
		cout<<ans<<endl;
	}
}