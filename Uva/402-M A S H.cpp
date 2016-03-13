#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <list>
using namespace std;

int main () {
	int n,x,p[30],k=1;
	bool a[60];
	while(scanf("%d%d",&n,&x)!=EOF){
		int i,j;
		for(i=0;i<20;i++)
			scanf("%d",p+i);
		for(i=1;i<=n;i++)
			a[i]=true;
		int nct,lp=n;
		for(i=0;i<20;i++){
			nct=0;
			for(j=1;j<=n;j++){
				if(lp==x)
					break;
				nct+=a[j];
				if(nct==p[i])
					a[j]=false,nct=0,lp--;
			}
			if(lp==x)
				break;
		}
		int psp=0;
		printf("Selection #%d\n",k++);
		for(i=1;i<=n;i++){
			if(a[i]){
				if(psp)
					putchar(' ');
				printf("%d",i);
				psp++;
			}
		}
		puts("");
		puts("");
	}
}
