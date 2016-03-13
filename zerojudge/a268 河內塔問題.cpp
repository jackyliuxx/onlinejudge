#include<iostream>
#include<cstdio>
#define M 1000000007
using namespace std;
int n,b[10010],e[10010],k[10010];
int s2(int i,int t,int *f){
	if(i<0)
		return 0;
	if(t!=f[i])
		return (k[i]+s2(i-1,6-t-f[i],f))%M;
	else
		return s2(i-1,t,f);
}

int main(){
	int i;
	for(i=1,k[0]=1;i<10010;i++)
		k[i]=(k[i-1]*2)%M;
	while(~scanf("%d",&n) && n){
		for(i=0;i<n;i++)
			scanf("%d",&b[i]);
		for(i=0;i<n;i++)
			scanf("%d",&e[i]);
		for(i=n-1;i>=0 && b[i]==e[i];i--);
		printf("%d\n",(s2(i-1,6-b[i]-e[i],b)+s2(i-1,6-b[i]-e[i],e)+(i>-1))%M);
	}
}
