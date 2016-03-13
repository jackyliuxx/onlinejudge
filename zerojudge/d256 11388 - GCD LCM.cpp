#include<iostream>
using namespace std;
int main(){
	int n,a,b;
	cin>>n;
	while(n--){
		cin>>a>>b;
		if(b%a)
			cout<<-1<<endl;
		else
			cout<<a<<' '<<b<<endl;
	}
}