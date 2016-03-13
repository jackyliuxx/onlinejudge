#include<iostream>
#include<stdio.h>
using namespace std;
int ans,a[1000000],b[1000000],k;
void wolala(int n,int v,int c){
	if(v<=100 && c>ans)
		ans=c;
	if(n>=k)
		return;
	if(v>100)
		return;
	wolala(n+1,v+a[n],c+b[n]);
	wolala(n+1,v,c);
}
	
int main(){
	int i;
	while(~scanf("%d",&k)){
		ans=0;
		for(i=0;i<k;i++)
			scanf("%d%d",&a[i],&b[i]);
		wolala(0,0,0);
		printf("%d\n",ans);
	}
}