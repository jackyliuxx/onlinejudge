#include<iostream>
using namespace std;
int x,y;
int gcd(int a,int b){
	int z;
	if(b==1){
		x=0,y=1;
		return 1;
	}
	if(b==0){
		return 0;
	}
	if(gcd(b,a%b)){
		z=x;
		x=y;
		y=z-(a/b)*y;
		return 1;
	}
	return 0;
}
int main(){
	int a,b;
	while(cin>>a>>b){
		if(a!=0 && b!=1 && gcd(a,b))
			cout<<(x<=0 ? x+b : x)<<endl;
		else
			cout<<"No Inverse\n";
	}
}