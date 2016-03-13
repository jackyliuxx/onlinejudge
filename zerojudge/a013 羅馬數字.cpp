#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main(){
	char r[9]={'I','V','X','L','C','D','M','A','A'};
	int p[7]={1,5,10,50,100,500,1000};
	string ca,cb;
	int a,b,i,j,ans;
	while(cin>>ca,ca!="#"){
		a=b=0;
		cin>>cb;
		for(i=0;i<ca.size();i++){
			for(j=0;j<7;j++){
				if(ca[i]==r[j]){
					a+=p[j];
					if(j%2){
						if(i>0 && j>0 && ca[i-1]==r[j-1])
							a-=2*p[j-1];
					}
					else{
						if(i>0 && j>1 && ca[i-1]==r[j-2])
							a-=2*p[j-2];
					}
				}
			}
		}
		for(i=0;i<cb.size();i++){
			for(j=0;j<7;j++){
				if(cb[i]==r[j]){
					b+=p[j];
					if(j%2){
						if(i>0 && j>0 && cb[i-1]==r[j-1])
							b-=2*p[j-1];
					}
					else{
						if(i>0 && j>1 && cb[i-1]==r[j-2])
							b-=2*p[j-2];
					}
				}
			}
		}
				if(b>a)
					swap(a,b);
				ans=a-b;
				if(ans){
					for(i=6;i>=0;i-=2){
						j=ans/p[i];
						ans%=p[i];
						if(j==9)
							cout<<r[i]<<r[i+2],j-=9;
						else if(j>=5)
							cout<<r[i+1],j-=5;
						else if(j==4)
							cout<<r[i]<<r[i+1],j-=4;
						while(j--)
							cout<<r[i];
					}
					cout<<endl;
				}
				else cout<<"ZERO\n";
	}
}