#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
int dd[6]={1,2,4,10,20,40};
int hm(int n){
	int ret=0,i;
	for(i=5;i>=0;i--){
		while(n/dd[i]){
			ret+=n/dd[i];
			n%=dd[i];
		}
	}
	return ret;
}
int main(){
	queue<int> d;
	int now,a[150],i,j,s[6],n2,ans,hhh;
	double n;
	while(scanf("%d%d%d%d%d%d",&s[0],&s[1],&s[2],&s[3],&s[4],&s[5]),s[0]+s[1]+s[2]+s[3]+s[4]+s[5]){
		scanf("%lf",&n);
		for(i=0;i<150;i++){
			a[i]=-1;
		}
		a[0]=0;
		n2=(int ((n+0.00499)*100))/5;
		for(i=0;i<6;i++)
			for(j=0;j<s[i];j++)
				d.push(dd[i]);
		while(d.empty()==false){
			now=d.front();
			d.pop();
			for(i=150-now-1;i>=0;i--)
				if(a[i]!=-1 && (a[i+now]==-1 || a[i]+1 < a[i+now]))
					a[i+now]=a[i]+1;
		}
		ans=9999;
		for(i=n2;i<150;i++){
			if(a[i]>0){
				hhh=hm(i-n2);
				if(a[i]+hhh<ans)
					ans=a[i]+hhh;
			}
		}
		printf("%3d\n",ans);
	}
}