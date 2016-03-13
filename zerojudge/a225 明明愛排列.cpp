#include<iostream>
using namespace std;
int main(){
	int i,n,j,a[1000];
	while(cin>>n){
		for(i=0;i<n;i++)
			cin>>a[i];
		for(j=0;j<n-1;j++){
			for(i=0;i<n-1;i++){
				if(a[i]%10>a[i+1]%10)
					swap(a[i],a[i+1]);
				else if(a[i]%10==a[i+1]%10 && a[i]<a[i+1])
					swap(a[i],a[i+1]);
			}
		}
		for(i=0;i<n;i++)
			cout<<a[i]<<' ';
		cout<<endl;
	}
}