#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,i;
	int a[1000];
	while(cin>>n){
		for(i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		for(i=0;i<n;i++)
			cout<<a[i]<<' ';
		cout<<endl;
	}
}