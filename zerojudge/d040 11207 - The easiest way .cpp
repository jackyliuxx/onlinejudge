#include <iostream>
using namespace std;
int main(){
	long long n,a,b,x,s,ss,nn; // x=輸出 s=正方形邊長*4
	while(cin>>n,n){
		x=0;
		ss=0;
		nn=n;
		while(nn--){
			cin>>a>>b;
			if(a>b)
				swap(a,b);
			if(a*4<=b)
				s=a*4;
			else
				if((a*4)>b && (a*2)<b)
					s=b;
				else
				    s=a*2;
			if(s>ss){
				ss=s;
				x=n-nn;
			}
		}
		cout<<x<<endl;
	}
}