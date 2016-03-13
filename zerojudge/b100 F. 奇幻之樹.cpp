#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int main(){
	int a,b,lfa,lfb,rfa,rfb,ax,bx;
	while(scanf("%d%d",&a,&b),a || b){
		ax=bx=1;
		lfa=rfb=0;
		lfb=rfa=1;
		while(a!=ax||b!=bx){
			if((double)a/b > (double)ax/bx){
				printf("R");
				lfa=ax;
				lfb=bx;
				ax+=rfa;
				bx+=rfb;
			}
			else{
				printf("L");
				rfa=ax;
				rfb=bx;
				ax+=lfa;
				bx+=lfb;
			}
		}
		printf("\n");
	}
}