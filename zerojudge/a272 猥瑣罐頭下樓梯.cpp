#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int main () {
	int n,a,b,c,d,a1,b1,c1,d1,ar,br,cr,dr,ar1,br1,cr1,dr1,m=10007;
	while(cin>>n){
		a=1;b=1;c=1;d=0;
		ar=1;br=1;cr=1;dr=1;
		while(n){
			if(n%2){
				a1=a;b1=b;c1=c;d1=d;
				ar1=ar;br1=br;cr1=cr;dr1=dr;
				ar=((ar1*a1)+(br1*c1))%m;
				br=((ar1*b1)+(br1*d1))%m;
				cr=((a1*cr1)+(c1*dr1))%m;
				dr=((cr1*b1)+(dr1*d1))%m;
			}
			a1=a;b1=b;c1=c;d1=d;
			a=((a1*a1)+(b1*c1))%m;
			b=((a1*b1)+(b1*d1))%m;
			c=((a1*c1)+(c1*d1))%m;
			d=((c1*b1)+(d1*d1))%m;
			n/=2;
		}
		cout<<br<<endl;
	}
}
