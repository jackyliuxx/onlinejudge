#include<iostream>
using namespace std;
int main(){
	long long d,n,d1,ans,dn;
	while(cin>>d){
		ans=0;
		d1=1;
		dn=1;
		for(n=1;n<=50;n++){
			ans+=dn;
			dn+=d1;
			d1+=d;
		}
		cout<<ans<<endl;
	}
	system("PAUSE");
}