#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
using namespace std;
int main(){
	int n,a[10000],b[10000],k,i;
	double j;
	while(~scanf("%d",&n)){
		k=0;
		for(i=n+1;i<=2*n;i++){
			j=((double)i* n)/(i-n);
			if( j==ceil(j) )
				a[k]=i,b[k]=int(j),k++;
		}
		printf("%d\n",k);
		for(i=0;i<k;i++)
			printf("1/%d = 1/%d + 1/%d\n",n,b[i],a[i]);
	}
}