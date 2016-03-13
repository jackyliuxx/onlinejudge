#include<iostream>
using namespace std;
int main(){
	int a,n;
	while(cin>>a>>n){
		if(a==n)
			cout<<n<<endl;
		else
			cout<<n+1<<endl;
	}
}