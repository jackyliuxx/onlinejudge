#include<iostream>
using namespace std;
int main(){
	long long n,f,g,i;
	while(cin>>n){
		f=g=0;
		for(i=1;i<=n;i++){
			f=f+i;
			g=f+g;
		}
		cout<<f<<' '<<g<<endl;
	}
}