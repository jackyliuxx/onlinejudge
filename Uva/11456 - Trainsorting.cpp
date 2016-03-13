#include<iostream>
#include<cstring>
#include<algorithm>
#include<stdio.h>
using namespace std;
int main(){
	int i,j,t,n;
	cin>>t;
	while(t--){
		int a[2010],b[2010],tr[2010],ans;  //a »¼´î b »¼¼W
		cin>>n;
		for(i=0;i<n;i++)
			cin>>tr[i];
		reverse(tr,tr+n);
		ans=0;
		for(i=0;i<n;i++){
			a[i]=b[i]=1;
			for(j=0;j<i;j++){
				if(tr[j]<tr[i] && a[j]+1>a[i])
					a[i]=a[j]+1;
				if(tr[j]>tr[i] && b[j]+1>b[i])
					b[i]=b[j]+1;
			}
			if(a[i]+b[i]>ans)
				ans=a[i]+b[i];
		}
		cout<<ans-1+(ans==0)<<endl;
	}
}