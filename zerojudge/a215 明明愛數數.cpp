#include<iostream>
using namespace std;
int main(){
	int i,n,m,a;
	while(cin>>n>>m){
		a=n;
		for(i=1;a<=m;i++)
			n+=1,a+=n;
		cout<<i<<endl;
	}
}