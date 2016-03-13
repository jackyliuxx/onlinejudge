#include <stdio.h>
#include <iostream>
using namespace std;
struct minute {
	int p,s[25];
} a[100000];
int song[100000];
int main () {
	int n,t,i,j,k;
	while(cin>>n>>t) {
		for(i=0; i<t; i++)
			cin>>song[i];
		for(i=0; i<=n; i++)
			a[i].p=-1;
		a[0].p=0;
		for(i=0; i<t; i++) {
			for(j=n-song[i]; j>=0; j--) {
				if(a[j].p!=-1 && a[j+song[i]].p==-1) {
					a[j+song[i]].p=0;
					for(k=0; k<a[j].p; k++)
						a[j+song[i]].s[a[j+song[i]].p++]=a[j].s[k];
					a[j+song[i]].s[a[j+song[i]].p++]=song[i];
				}
			}
		}
		for(i=n; i>=0; i--)
			if(a[i].p!=-1)
				break;
		for(j=0; j<a[i].p; j++)
			printf("%d ",a[i].s[j]);
		printf("sum:%d\n",i);
	}
}
