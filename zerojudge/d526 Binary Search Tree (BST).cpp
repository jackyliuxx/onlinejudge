#include<iostream>
#include<stdio.h>
using namespace std;
int a[1010][3];
void bst(int ax,int n){
	if(a[ax][0]<a[n][0]){
		if(a[n][1]==-1)
			a[n][1]=ax;
		else
			bst(ax,a[n][1]);
	}
	else{
		if(a[n][2]==-1)
			a[n][2]=ax;
		else
			bst(ax,a[n][2]);
	}
}
void pr(int n){
	if(n<0)
		return;
	printf("%d ",a[n][0]);
	pr(a[n][1]);
	pr(a[n][2]);
}
int main(){
	int n,i;
	while(~scanf("%d",&n)){
		for(i=0;i<1010;i++)
			a[i][1]=a[i][2]=-1;
		for(i=0;i<n;i++)
			scanf("%d",&a[i][0]);
		for(i=1;i<n;i++)
			bst(i,0);
		pr(0);
		printf("\n");
	}
}