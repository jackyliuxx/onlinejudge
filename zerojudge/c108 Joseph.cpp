#include<iostream>
using namespace std;
int main(){
	int n,i,w,n2,j,a[14];
	for(n=1;n<=14;n++){
		for(i=1;1;i++){
			if(i%(n*2) >0 && i%(n*2)<=n)
				continue;
			w=0;
			n2=n*2;
			while(n2>n){
				w+=i-1;
				w%=n2;
				if(w<n)
					break;
				n2--;
				w%=n2;
			}
			if(n2==n)
				break;
		}
		a[n-1]=i;
	}
	while(cin>>n,n){
		cout<<a[n-1]<<endl;
	}
}