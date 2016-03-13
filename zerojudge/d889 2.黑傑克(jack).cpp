#include<iostream>
using namespace std;
int main(){
	int n,c,d,i,a[10001]={},e;
	cin>>n;
	d=30;
	e=0;
	while(n--)
		cin>>c,a[c]=1;
	for(i=0;i<10001;i++){
		if(d==0)
			break;
		if(a[i]){
			if(e<0)
				e=5;
			else
				e+=5;
		}
		if(e>-1)
			d=30;
		d--;
		e--;
	}
	cout<<i<<endl;
}