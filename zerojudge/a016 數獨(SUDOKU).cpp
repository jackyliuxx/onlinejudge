#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int n,i,j,g;
	while(cin>>ws,cin.peek()!=EOF){
		int a[9]={},b[9]={},c[9]={};
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				cin>>n;
				a[i]+=1<<n-1;
				b[j]+=1<<n-1;
				c[i/3*3+j/3]+=1<<n-1;
			}
		}
		g=511;
		for(i=0;i<9;i++)
			g&=a[i]&b[i]&c[i];
		cout<<(g==511 ? "yes\n" : "no\n");
	}
}