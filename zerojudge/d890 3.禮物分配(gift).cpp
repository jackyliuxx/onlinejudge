#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int gift[510];
int a,b;
int main(){
	int n,k,i;
	while(cin>>n>>k){
		for(i=0;i<n;i++)
			cin>>gift[i];
		sort(gift,gift+n);
		for(i=n-1;i>=0;i--){
			if(a<b)
				a+=gift[i];
			else
				b+=gift[i];
		}
		if(a>b)
			swap(a,b);
		cout<<a<<' '<<b<<endl;
	}
}