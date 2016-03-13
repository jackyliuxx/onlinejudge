#include<iostream>
#include<stdio.h>
using namespace std;
struct wawa{
	int v,c;
};
int main(){
	int i,k,b[2][101],j;
	wawa a[100000];
	while(~scanf("%d",&k)){
		for(i=0;i<101;i++)
			b[0][i]=b[1][i]=0;
		for(i=0;i<k;i++)
			scanf("%d%d",&a[i].v,&a[i].c);
		for(i=0;i<k;i++){
			for(j=0;j<101;j++)
				if(j+a[i].v < 101 && b[1][j+a[i].v] < b[0][j]+a[i].c)
					b[1][j+a[i].v]=b[0][j]+a[i].c;
			for(j=0;j<101;j++)
				b[0][j]=b[1][j];
		}
		printf("%d\n",b[0][100]);
	}
}