#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int a,b,c;
	while(~scanf("%d%d",&a,&b)){
		printf("[%d;",a/b);
		c=b;
		b=a%b;
		a=c;
		while(b>1){
			printf("%d,",a/b);
			c=b;
			b=a%b;
			a=c;
		}
		printf("%d]\n",a);
	}
}