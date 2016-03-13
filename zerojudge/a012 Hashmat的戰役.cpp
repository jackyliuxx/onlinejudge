#include<iostream>
using namespace std;
int main(){
	long long n1,n2,ans;
	while(cin>>n1>>n2){
		ans=n1-n2;
		if(ans<0)
			ans=-ans;
		cout<<ans<<endl;
	}
}