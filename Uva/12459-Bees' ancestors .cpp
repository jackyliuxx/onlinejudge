#include<iostream>
using namespace std;
int main(){
	long long i,n,j,k;
	while(cin>>n,n){
		i=1;
		j=1;
		while(n--){
			k=j;
			j+=i;
			i=k;
		}
		cout<<i<<endl;
	}
}