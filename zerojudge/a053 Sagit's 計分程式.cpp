#include<iostream>
using namespace std;
int main(){
	int n,i,a;
	while(cin>>n){
		a=0;
		for(i=0;i<n;i++){
			if(i<10)
				a+=6;
			else if(i<20)
				a+=2;
			else
				a+=1;
		}
		if(a>100)
			a=100;
		cout<<a<<endl;
	}
}