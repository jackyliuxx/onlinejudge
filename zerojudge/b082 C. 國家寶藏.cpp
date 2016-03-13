#include<iostream>
#include<stdio.h>
using namespace std;
struct goopie{
	char ch;
	int next;
};
int main(){
	goopie a[500];
	int n,m,now,k,i;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&m);
		now=300;
		cin>>k>>a[300].ch>>a[300].next;
		for(i=1;i<m;i++){
			cin>> k ;
			cin>> a[k].ch >> a[k].next;
		}
		while(m--){
			printf("%c",a[now].ch),now=a[now].next;
		}
		printf("\n");
	}
}