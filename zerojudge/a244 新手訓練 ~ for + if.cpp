#include<iostream>
using namespace std;
int main(){
	int n,a,b,c;
	cin>>n;
	while(n--){
		cin>>a>>b>>c;
		if(a==1)
			cout<<(long long)b+c<<endl;
		else if(a==2)
			cout<<b-c<<endl;
		else if(a==3)
			cout<<(long long)b*c<<endl;
		else
			cout<<b/c<<endl;
	}
}