#include<iostream>
using namespace std;
int a,a2;
char m;
int eng(char n){
	if(n<'a')
		return 0;
	if(n<=m)
		return 1000000;
	a2=n-m;
	m=n;
	cin.get(n);
	return a2+eng(n);
}
int main(){
	char n;
	int ans;
	while(cin>>n){
		m='a'-1;
		ans=eng(n);
		if(ans<1000000)
			cout<<ans<<endl;
		else
			cout<<0<<endl;
	}
}