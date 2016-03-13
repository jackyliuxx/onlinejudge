#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	int n,m,b[1000],i,j,k,l;
	double a[1000],max,other;
	cin>>n;
	while(n--){
		cin>>m;
		l=1;
		for(i=0;i<m;i++){
			max=other=0;
			for(j=0;j<m;j++){
				cin>>a[j];
				if(a[j]<0)
					a[j]=-a[j];
				if(max<a[j])
					other+=max,max=a[j],b[i]=j;
				else
					other+=a[j];
			}
			if(other>=max)
				l=0;
		}
		sort(b,b+m);
		for(i=0;i<m-1;i++){
			if(b[i]==b[i+1]){
				l=0;
				break;
			}
		}
		if(l)
			printf("yes\n");
		else
			printf("no\n");
	}
}