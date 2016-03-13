#include<iostream>
using namespace std;
int main(){
	int n,a,f;
	while(cin>>n){
		f=0;
		while(n--)
			cin>>a,f+=59-a;
		cout<<(f>=0 ? "yes" : "no")<<endl;
	}
}