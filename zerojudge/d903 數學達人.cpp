#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
	long long n,ans;
	while(cin>>n){
		long long k,i;
		ans=0;
		for(i=0;i<n;i++)
			ans+=i*i;
		for(k=0,i=0;i<n;i++,k=i*i){
			ans+=(n-i-1)*k;
		}
		cout<<ans<<endl;
	}
}

