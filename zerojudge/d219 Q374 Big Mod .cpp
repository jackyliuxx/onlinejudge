#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int main () {
	int b,p,m,kb,kp,lb,n,o;               //n©ó¼Æ
	while(cin>>b>>p>>m){
		kb=b;
		kp=p;
		n=0;
		o=0;
		lb=b%m;
		while(kp){
			if(kp%2){
				kp--;
				n++;
			}
			if(kp/2)
				o++;
			kp/=2;
		}
		while(o){
			kb*=kb;
	
			o--;
		}
		while(n){
			kb*=kb;
			n--;
		}
		cout<<kb%m<<endl;
	}
}