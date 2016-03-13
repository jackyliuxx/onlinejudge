#include<bits/stdc++.h>
using namespace std;

int cc(int p,int t){
	return max(3*p/10,p-p/250*t);
}

int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(cc(a,c)>cc(b,d))
		puts("Misha");
	else if(cc(a,c)<cc(b,d))
		puts("Vasya");
	else
		puts("Tie");
}
