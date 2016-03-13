#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n,t;
	static int a[110000];
	scanf("%d%d",&n,&t);
	for(int i=0;i<n-1;i++)
		scanf("%d",a+i+1);
	int i;
	for(i=1;i<t;i+=a[i]);
	if(i==t)
		puts("YES");
	else
		puts("NO");
}
