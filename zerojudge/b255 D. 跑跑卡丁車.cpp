#include<iostream>            
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
struct dri{
	string name;
	double t;
}a[100000];
double b[100000];
int main(){
	int n,i,j,h,m,n2;
	char ch;
	double w;
	while(scanf("%d",&n),n){
		for(i=0;i<n;i++){
			cin>>a[i].name;
			scanf("%d%c%d%c",&h,&ch,&m,&ch);
			cin>>a[i].t;
			m+=h*60;
			a[i].t+=m*60;
			b[i]=a[i].t;
		}
		sort(b,b+n);
		w=b[n/3-1];
		printf("LIST START\n");
		for(i=0;i<n;i++)
			if(a[i].t<=w)
				cout<<a[i].name<<endl;
		/*
		for(i=0;i<n;i++)
			for(j=n2-1;j>=i+1;j--)
				if(a[j].t<a[j-1].t)
					swap(a[j].na,a[j-1].na),swap(a[j].t,a[j-1].t);
		for(i=0;i+1<=n || a[i].t==a[i-1].t;i++)
			cout<<name[a[i].na]<<endl;
			*/
		printf("LIST END\n");
	}
}