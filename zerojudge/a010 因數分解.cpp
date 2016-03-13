#include<iostream>
using namespace std;

int a[500000],n;

void ans(int x){
	if(n==1)
		return;
	if(x==2){
		if(n%x==0){
			a[0]++;
			n/=x;
			ans(x);
		}
	}
	else
		if(n%x==0){
			a[(x-1)/2]++;
			n/=x;
			ans(x);
		}
}
int main(){
	int x,i,j;	
	while(cin>>n){
		j=0;
		for(i=0;i<500000;i++)
			a[i]=0;
		ans(2);
		for(x=3;n!=1;x+=2)
			ans(x);
		if(a[0]>0){
			cout<<2;
			if(a[0]>1)
				cout<<'^'<<a[0];
			j++;
		}
		for(i=1;i<500000;i++){
			if(a[i]>0){
				if(j!=0)
					cout<<" * ";
				cout<<i*2+1;
				if(a[i]>1)
					cout<<'^'<<a[i];
				j++;
			}
		}
		cout<<endl;
	}
}
