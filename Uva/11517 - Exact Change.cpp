#include <stdio.h>
#include <iostream>
using namespace std;

int main () {
	int a[20010],n,t,need,i,j,c;
	cin>>t;
	while(t--){
		for(i=0;i<20010;i++)
			a[i]=-1;
		a[0]=0;
		cin>>need>>n;
		while(n--){
			cin>>c;
			for(i=20010-c;i>=0;i--)
				if(a[i]!=-1 &&( a[i+c]==-1 || a[i+c]>a[i]+1))
					a[i+c]=a[i]+1;
		}
		for(i=need;i<20010;i++)
			if(a[i]!=-1)
				break;
		printf("%d %d\n",i,a[i]);
	}
}
