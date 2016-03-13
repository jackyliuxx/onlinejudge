#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int t,n,i,k,m,a[70000],w,ans,o=1;
	cin>>t;
	while(t--){
		cin>>n>>k>>m;
		for(i=0;i<n;i++)
			a[i]=i+1;
		w=-1;
		while(m--){
			w=(w+k)%n;
			if(m==0)
				ans=a[w];
			for(i=w;i<n-1;i++)
				a[i]=a[i+1];
			w--;
			n--;
		}
		printf("Case %d: %d\n",o++,ans);
	}
}