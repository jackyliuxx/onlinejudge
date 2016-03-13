#include<iostream>
using namespace std;
int main(){
	int i,n,a[77]={1,1,2};
	for(i=3;i<=76;i++)
		a[i]=a[i-3]+a[i-2];
	while(cin>>n){
		cout<<a[n]<<endl;
	}
}